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
using WinFormStringCnvClass;

namespace TextReplaceCopy
{
    public partial class Form1 : Form
    {
        string thisExeDirPath;

        public Form1()
        {
            InitializeComponent();
            thisExeDirPath = Path.GetDirectoryName(Application.ExecutablePath);
        }

        private void button_Copy_Click(object sender, EventArgs e)
        {
            try
            {
                string srcDir = textBox_SrcPath.Text.Trim();
                string dstDir = textBox_TargetPath.Text.Trim();

                if (string.IsNullOrWhiteSpace(srcDir) || string.IsNullOrWhiteSpace(dstDir))
                {
                    return;
                }

                if (!Directory.Exists(srcDir))
                {
                    return;
                }

                if (!Directory.Exists(dstDir))
                {
                    Directory.CreateDirectory(dstDir);
                }

                var replaceDict = new Dictionary<string, string>();
                var lines = textBox_ReplaceList.Lines;
                foreach (var line in lines)
                {
                    var parts = line.Split('\t');
                    if (parts.Length == 2)
                    {
                        replaceDict[parts[0]] = parts[1];
                    }
                }

                string[] extensions = { ".c", ".cpp", ".h", ".hpp" };

                var files = Directory.GetFiles(srcDir, "*.*", SearchOption.AllDirectories)
                                     .Where(f => extensions.Contains(Path.GetExtension(f).ToLower()))
                                     .ToList();

                foreach (var srcFilePath in files)
                {
                    string relativePath = srcFilePath.Substring(srcDir.Length).TrimStart(Path.DirectorySeparatorChar);
                    string dstFilePath = Path.Combine(dstDir, relativePath);

                    string dstFileDir = Path.GetDirectoryName(dstFilePath);
                    if (!Directory.Exists(dstFileDir))
                    {
                        Directory.CreateDirectory(dstFileDir);
                    }

                    File.Copy(srcFilePath, dstFilePath, true);

                    string content = File.ReadAllText(dstFilePath, Encoding.UTF8);

                    foreach (var kvp in replaceDict)
                    {
                        content = content.Replace(kvp.Key, kvp.Value);
                    }

                    File.WriteAllText(dstFilePath, content, Encoding.UTF8);
                }

            }
            catch (Exception ex)
            {
            }
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
    }
}
