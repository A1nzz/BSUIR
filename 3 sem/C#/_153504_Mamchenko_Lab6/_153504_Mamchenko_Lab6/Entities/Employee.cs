using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Mamchenko_Lab6.Entities
{
    public class Employee
    {
        public string? Name { get; set; }

        public int? Salary { get; set; }
        public bool? IsFree { get; set; }
        
        public Employee()
        {
            Name = null;
            Salary = null;
            IsFree = null;
        }

        public Employee(string name, int salary, bool isFree)
        {
            Name = name;
            Salary = salary;
            IsFree = isFree;
        }
    }
}
