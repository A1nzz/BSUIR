using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Mamchenko_Lab5.Domain.Entities
{
    public class Kitchen
    {
        public string? Name { get; set; }
        
        public int? Area { get; set; }
        
        public Kitchen() {
            Name = null;
            Area = null;
        }
        
        public Kitchen(string? name, int? area)
        {
            Name = name;
            Area = area;
        }
    }
}
