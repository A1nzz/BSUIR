using System;
using Task2.Services;

namespace Task2
{
    class Program
    {
        static void Main(string[] args)
        {
            int z;
            Console.Write("Enter number:");
            z = Convert.ToInt32(Console.ReadLine());
            Class1 obj = new Class1();
            Console.WriteLine(obj.f1(z));
        }
    }
}
