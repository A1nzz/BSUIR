using System;
using _153504_Mamchenko_Lab3.Entities;

namespace _153504_Mamchenko_Lab3 // Note: actual namespace depends on the project name.
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Hotel hotel = new();
            Journal journal = new();
            hotel.AddingNotify += journal.RecordEventAddingClientsAndRooms;
            hotel.BuyingNotify += (sender, e) => Console.WriteLine($"Описание: {e.Message} Название сущности: {sender?.GetType().Name}");
            
            hotel.AddRoom(new Room(300, 4));
            hotel.AddRoom(new Room(200, 2));
            hotel.AddRoom(new Room(200, 3));

            hotel.AddRoom(new Room(6000, 1));

            hotel.AddClient(new Client("Ivan"));
            hotel.AddClient(new Client("Pavel"));

            hotel.LogIn("Ivan");
            hotel.BuyRoom(2);
            hotel.BuyRoom(4);
            hotel.LogOut();
            hotel.LogIn("Pavel");
            hotel.BuyRoom(1);
            var sortedList = hotel.GetSortedListOfRooms();
            Console.WriteLine("Список комнат:");
            foreach (var item in sortedList)
            {
                Console.WriteLine(item);
            }
            Console.WriteLine(hotel?.GetGeneralPriceOfAllBookingRooms());
            Console.WriteLine($"Клиент заплативший максимальную сумму: {hotel?.GetClientNameWithMaxPriceOfAllRooms()}");
            Console.WriteLine("Количество клиентов заплативших больше 499: " + hotel?.GetClientCountThatPaidMoreThanDefinePrice(499));
            List<(int, int)> list = hotel!.GetListGroupedByPrice().ToList();
            foreach ((int, int)item in list)
            {
                Console.WriteLine($"Количество комнат с ценой {item.Item1}: {item.Item2}");
            }  
        }
    }
}
