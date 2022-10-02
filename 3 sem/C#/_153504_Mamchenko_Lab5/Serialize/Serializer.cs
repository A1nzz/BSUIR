using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.Json;
using System.Xml.Serialization;
using System.Xml.Linq;
using _153504_Mamchenko_Lab5.Domain.Entities;
using _153504_Mamchenko_Lab5.Domain.Interfaces;

namespace Serialize
{
    public class Serializer : ISerialize
    {
        public IEnumerable<Restaurant> DeSerializeByLINQ(string fileName)
        {
            XDocument xdoc = XDocument.Load(fileName);
            var rests = from restaurant in xdoc?.Element("restaurants")?.Elements("restaurant")
                        select new Restaurant(
                            restaurant?.Element("name")?.Value,
                            new Kitchen(
                            restaurant?.Element("kitchen")?.Element("name")?.Value,
                            int.Parse(restaurant?.Element("kitchen")?.Element("area")?.Value)
                        ));
            return rests;
        }

        public IEnumerable<Restaurant> DeSerializeJSON(string fileName)
        {
            string json = File.ReadAllText(fileName);
            return JsonSerializer.Deserialize<IEnumerable<Restaurant>>(json);
        }

        public IEnumerable<Restaurant> DeSerializeXML(string fileName)
        {
            XmlSerializer xmlSerializer = new XmlSerializer(typeof(List<Restaurant>));
            
            using (FileStream fs = new FileStream(fileName, FileMode.OpenOrCreate))
            {
                IEnumerable<Restaurant>? list = xmlSerializer.Deserialize(fs) as IEnumerable<Restaurant>;
                return list;
            }
        }

        public void SerializeByLINQ(IEnumerable<Restaurant> restaurants, string fileName)
        {
            XDocument xdoc = new XDocument(new XElement("restaurants",
                                            from listItem in restaurants
                                            select new XElement("restaurant",
                                                new XElement("name", listItem.Name),
                                                new XElement("kitchen",
                                                    new XElement("name", listItem?.Kitchen?.Name),
                                                    new XElement("area", listItem?.Kitchen?.Area)))));
            xdoc.Save(fileName);

        }

        public void SerializeJSON(IEnumerable<Restaurant> restaurants, string fileName)
        {
            var options = new JsonSerializerOptions
            {
                WriteIndented = true
            };
            string json = JsonSerializer.Serialize(restaurants, options);
            File.WriteAllText(fileName, json);
        }

        public void SerializeXML(IEnumerable<Restaurant> restaurants, string fileName)
        {
            XmlSerializer xmlSerializer = new XmlSerializer(typeof(List<Restaurant>));
            
            using (FileStream fs = new FileStream(fileName, FileMode.OpenOrCreate))
            {
                xmlSerializer.Serialize(fs, restaurants);
            }
        }
    }
}
