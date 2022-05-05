using System;

namespace Lab6 // Note: actual namespace depends on the project name.
{
    public class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            Doll doll = new Doll("Ulia", "female", 1200, 5);
            doll.GetInfo();
            doll.GetageRestriction();
            doll.Buy();
            Console.WriteLine("Total sum of lego: " + doll.getTotalSum());

            Car car = new Car("BMW", 20000, 2);
            car.GetInfo();
            car.GetageRestriction();
            car.Buy();
            Console.WriteLine("Total sum of lego: " + car.getTotalSum());

            Lego legoPolice = new Lego("Lego City", 120, 1400, 9);
            legoPolice.GetInfo();
            legoPolice.GetageRestriction();
            legoPolice.Buy();
            Console.WriteLine("Total sum of lego: " + legoPolice.getTotalSum());
        }
    }
}
