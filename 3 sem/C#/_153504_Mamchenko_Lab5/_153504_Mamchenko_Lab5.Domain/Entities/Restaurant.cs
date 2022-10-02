using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Mamchenko_Lab5.Domain.Entities
{
    public class Restaurant
    {
        public string? Name { get; set; }

        public Kitchen? Kitchen { get; set; }

        public Restaurant()
        {
            Name = null;
            Kitchen = null;
        }

        public Restaurant(string? name, Kitchen? kitchen)
        {
            Name = name;
            Kitchen = kitchen;
        }
    }
}
