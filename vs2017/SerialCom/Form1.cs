using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.IO.Ports;
using WinFormStringCnvClass;

namespace FTDI_AccessCode
{
    public partial class Form1 : Form
    {
        string thisExeDirPath;
        public Form1()
        {
            InitializeComponent();
            thisExeDirPath = Path.GetDirectoryName(Application.ExecutablePath);
            initPortNameItems();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Filter = "TEXT|*.txt";
            if (false && ofd.ShowDialog() == DialogResult.OK)
            {
                WinFormStringCnv.setControlFromString(this, File.ReadAllText(ofd.FileName));
            }
            else
            {
                string paramFilename = Path.Combine(thisExeDirPath, "_param.txt");
                if (File.Exists(paramFilename))
                {
                    WinFormStringCnv.setControlFromString(this, File.ReadAllText(paramFilename));
                }
            }

        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            string FormContents = WinFormStringCnv.ToString(this);

            SaveFileDialog sfd = new SaveFileDialog();
            sfd.Filter = "TEXT|*.txt";

            if (false && sfd.ShowDialog() == DialogResult.OK)
            {

                File.WriteAllText(sfd.FileName, FormContents);
            }
            else
            {
                string paramFilename = Path.Combine(thisExeDirPath, "_param.txt");
                File.WriteAllText(paramFilename, FormContents);
            }

        }

        private void initPortNameItems()
        {
            comboBox_PortName.Items.Clear();

            try
            {
                string[] portNames = SerialPort.GetPortNames();

                foreach (string port in portNames)
                {
                    comboBox_PortName.Items.Add(port);
                }

                if (comboBox_PortName.Items.Count > 0)
                {
                    comboBox_PortName.SelectedIndex = 0;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error " + ex.Message,
                                   "port Listup failed.", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void button_Connect_Click(object sender, EventArgs e)
        {
            if (button_Connect.Text == "Connect")
            {
                try
                {
                    string portName = comboBox_PortName.SelectedItem?.ToString();
                    int baudRate = int.Parse(comboBox_BoadRate.SelectedItem?.ToString() ?? "9600");
                    int dataBits = int.Parse(comboBox_DataBit.SelectedItem?.ToString() ?? "8");
                    StopBits stopBits = (StopBits)Enum.Parse(typeof(StopBits), comboBox_StopBit.SelectedItem?.ToString() ?? "One");
                    Parity parity = (Parity)Enum.Parse(typeof(Parity), comboBox_Parity.SelectedItem?.ToString() ?? "None");

                    serialPort1.PortName = portName;
                    serialPort1.BaudRate = baudRate;
                    serialPort1.DataBits = dataBits;
                    serialPort1.StopBits = stopBits;
                    serialPort1.Parity = parity;
                    serialPort1.ReadTimeout = 1000;
                    serialPort1.WriteTimeout = 1000;

                    if (!serialPort1.IsOpen)
                    {
                        serialPort1.Open();
                    }

                    button_Connect.Text = "DisConnect";
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error " + ex.Message,
                                    "Connection failed.", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
            else
            {
                try
                {
                    if (serialPort1 != null && serialPort1.IsOpen)
                    {
                        serialPort1.Close();
                        button_Connect.Text = "Connect";
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error " + ex.Message,
                                    "port close failed.", MessageBoxButtons.OK, MessageBoxIcon.Error);

                }
            }
        }

        private ushort calculateCRC(byte[] data)
        {
            ushort crc = 0xFFFF;

            foreach (byte b in data)
            {
                crc ^= b;
                for (int i = 0; i < 8; i++)
                {
                    if ((crc & 0x0001) != 0)
                        crc = (ushort)((crc >> 1) ^ 0xA001);
                    else
                        crc >>= 1;
                }
            }

            return crc;
        }


        public ushort[] readRegister(int serverAddress, int startRegisterAddress, int readRegisterCount)
        {
            if (serialPort1 == null || !serialPort1.IsOpen)
            {
                throw new InvalidOperationException("SerialPort is not open.");
            }

            // Query: [Address][Function=0x03][StartAddrHi][StartAddrLo][CountHi][CountLo]
            List<byte> frame = new List<byte>
            {
                (byte)serverAddress,
                0x03,
                (byte)((startRegisterAddress >> 8) & 0xFF),
                (byte)(startRegisterAddress & 0xFF),
                (byte)((readRegisterCount >> 8) & 0xFF),
                (byte)(readRegisterCount & 0xFF)
            };

            // CRC-16 [little endian]
            ushort crc = calculateCRC(frame.ToArray());
            frame.Add((byte)(crc & 0xFF));
            frame.Add((byte)((crc >> 8) & 0xFF));

            // send query 
            serialPort1.DiscardInBuffer();
            serialPort1.Write(frame.ToArray(), 0, frame.Count);

            // read responce
            try
            {
                // responce: [Address][Function][ByteCount][Data...][CRC_L][CRC_H]
                byte[] header = new byte[3];
                serialPort1.Read(header, 0, 3);

                if (header[0] != (byte)serverAddress || header[1] != 0x03)
                {
                    throw new InvalidOperationException("responce header is not correct");
                }

                int byteCount = header[2];
                byte[] data = new byte[byteCount + 2]; // +2: CRC byte
                serialPort1.Read(data, 0, data.Length);

                // CRC check
                List<byte> fullResponse = new List<byte>(header);
                fullResponse.AddRange(data);
                ushort receivedCrc = (ushort)(data[data.Length - 2] | (data[data.Length - 1] << 8));
                ushort calculatedCrc = calculateCRC(fullResponse.GetRange(0, fullResponse.Count - 2).ToArray());

                if (receivedCrc != calculatedCrc)
                {
                    throw new InvalidOperationException("CRC error");
                }

                int registerCount = byteCount / 2;
                ushort[] registers = new ushort[registerCount];
                for (int i = 0; i < registerCount; i++)
                {
                    registers[i] = (ushort)((data[i * 2] << 8) | data[i * 2 + 1]);
                }

                return registers;
            }
            catch (TimeoutException)
            {
                throw new TimeoutException("Modbus timeout");
            }
        }

        public void writeRegister(int serverAddress, ushort startRegisterAddress, ushort data)
        {
            if (serialPort1 == null || !serialPort1.IsOpen)
            {
                throw new InvalidOperationException("SerialPort is not open.");
            }

            // Query: [Address][Function=0x06][RegisterHi][RegisterLo][DataHi][DataLo]
            List<byte> frame = new List<byte>
            {
                (byte)serverAddress,
                0x06,
                (byte)((startRegisterAddress >> 8) & 0xFF),
                (byte)(startRegisterAddress & 0xFF),
                (byte)((data >> 8) & 0xFF),
                (byte)(data & 0xFF)
            };

            // CRC-16 [little endian]
            ushort crc = calculateCRC(frame.ToArray());
            frame.Add((byte)(crc & 0xFF)); 
            frame.Add((byte)((crc >> 8) & 0xFF));

            serialPort1.DiscardInBuffer();
            serialPort1.Write(frame.ToArray(), 0, frame.Count);

            // read responce
            byte[] response = new byte[8];
            try
            {
                serialPort1.Read(response, 0, response.Length);

                // check responce
                if (response[0] != (byte)serverAddress || response[1] != 0x06)
                {
                    throw new InvalidOperationException("Invalid response header.");
                }

                ushort receivedCrc = (ushort)(response[6] | (response[7] << 8));

                byte[] crcTarget = new byte[6];
                Array.Copy(response, 0, crcTarget, 0, 6);

                ushort calculatedCrc = calculateCRC(crcTarget);

                if (receivedCrc != calculatedCrc)
                {
                    throw new InvalidOperationException("CRC error: response is corrupted.");
                }

                Console.WriteLine("Register write successful.");
            }
            catch (TimeoutException)
            {
                throw new TimeoutException("Modbus response timeout.");
            }
        }



        public void writeRegister(int serverAddress, ushort startRegisterAddress, List<ushort> data)
        {
            if (serialPort1 == null || !serialPort1.IsOpen)
            {
                throw new InvalidOperationException("SerialPort is not open.");
            }

            int registerCount = data.Count;
            if (registerCount == 0)
            {
                throw new ArgumentException("Data list is empty.");
            }

            int byteCount = registerCount * 2;

            // Query: [Address][Function=0x10][StartAddrHi][StartAddrLo][CountHi][CountLo][ByteCount][Data...]
            List<byte> frame = new List<byte>
            {
                (byte)serverAddress,
                0x10,
                (byte)((startRegisterAddress >> 8) & 0xFF),
                (byte)(startRegisterAddress & 0xFF),
                (byte)((registerCount >> 8) & 0xFF),
                (byte)(registerCount & 0xFF),
                (byte)byteCount
            };
        
            foreach (ushort value in data)
            {
                frame.Add((byte)((value >> 8) & 0xFF));
                frame.Add((byte)(value & 0xFF));
            }

            // CRC-16 [little endian]
            ushort crc = calculateCRC(frame.ToArray());
            frame.Add((byte)(crc & 0xFF));
            frame.Add((byte)((crc >> 8) & 0xFF));

            serialPort1.DiscardInBuffer();
            serialPort1.Write(frame.ToArray(), 0, frame.Count);

            // read responce（ [Address][Function][StartAddrHi][StartAddrLo][CountHi][CountLo][CRC_L][CRC_H]）
            byte[] response = new byte[8];
            try
            {
                serialPort1.Read(response, 0, response.Length);

                if (response[0] != (byte)serverAddress || response[1] != 0x10)
                {
                    throw new InvalidOperationException("Invalid response header.");
                }

                byte[] crcTarget = new byte[6];
                Array.Copy(response, 0, crcTarget, 0, 6);
                ushort receivedCrc = (ushort)(response[6] | (response[7] << 8));
                ushort calculatedCrc = calculateCRC(crcTarget);

                if (receivedCrc != calculatedCrc)
                {
                    throw new InvalidOperationException("CRC error: response is corrupted.");
                }

                Console.WriteLine("Multiple register write successful.");
            }
            catch (TimeoutException)
            {
                throw new TimeoutException("Modbus response timeout.");
            }
        }

    }
}
