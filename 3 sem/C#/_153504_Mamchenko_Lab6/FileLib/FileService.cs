using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _153504_Mamchenko_Lab6.Interfaces;
using System.Text.Json;

namespace FileLib
{
    public class FileService<T> : IFileService<T> where T : class
    {
        public IEnumerable<T> ReadFile(string fileName)
        {
            string json = File.ReadAllText(fileName);
            return JsonSerializer.Deserialize<IEnumerable<T>>(json);
        }

        public void SaveData(IEnumerable<T> data, string fileName)
        {
            var options = new JsonSerializerOptions
            {
                WriteIndented = true
            };
            string json = JsonSerializer.Serialize(data, options);
            File.WriteAllText(fileName, json);
        }
    }
}
