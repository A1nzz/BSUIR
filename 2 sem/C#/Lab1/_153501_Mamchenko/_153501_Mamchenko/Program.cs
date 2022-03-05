using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153501_Mamchenko
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter the 1st number: ");
            int firstNumer = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter the 2nd number: ");
            int secondNumber = Convert.ToInt32(Console.ReadLine());
            int quotient = firstNumer / secondNumber;
            Console.WriteLine("The result of dividing two numbers: {0}", quotient);
        }
    }
}
