


using System;

namespace Lab4 // Note: actual namespace depends on the project name.
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Hotel somehotel = Hotel.GetHotel("Hilton");
            Console.WriteLine(somehotel.Name);
            Hotel somehotel2 = Hotel.GetHotel("NeHilton");
            Console.WriteLine(somehotel2.Name);

            somehotel.OccupiedPlaces = 5;

            somehotel.EditRate = 15;
            Console.WriteLine(somehotel.EditRate);

            Console.WriteLine(somehotel.TotalRate());

        }
    }
}