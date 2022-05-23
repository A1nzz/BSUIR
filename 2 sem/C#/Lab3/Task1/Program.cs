using System;
using Task1;

namespace Task1
{
    class Program
    {
        static void Main(string[] args)
        {
            int a;
            Console.Write("Enter number:");
            a = Convert.ToInt32(Console.ReadLine());
            Class1 obj = new Class1();
            a = obj.f1(a);
            Console.WriteLine(a);
        }
    }
}
