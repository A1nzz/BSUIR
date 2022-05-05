using System;
using Task3;

namespace Task3
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter date: ");
            string dayOfWeek = Console.ReadLine();
            DateService obj = new DateService();
            Console.WriteLine(obj.GetDay(dayOfWeek));
            Console.WriteLine(obj.GetDaysSpan(20, 02, 2022));
        }
    }
}
