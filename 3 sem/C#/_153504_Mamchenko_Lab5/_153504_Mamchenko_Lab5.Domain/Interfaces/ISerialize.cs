using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _153504_Mamchenko_Lab5.Domain.Entities;

namespace _153504_Mamchenko_Lab5.Domain.Interfaces
{
    public interface ISerialize
    {
        IEnumerable<Restaurant> DeSerializeByLINQ(string fileName);
        IEnumerable<Restaurant> DeSerializeXML(string fileName);
        IEnumerable<Restaurant> DeSerializeJSON(string fileName);
        void SerializeByLINQ(IEnumerable<Restaurant> xxx, string fileName);
        void SerializeXML(IEnumerable<Restaurant> xxx, string fileName);
        void SerializeJSON(IEnumerable<Restaurant> xxx, string fileName);        
    }
}
