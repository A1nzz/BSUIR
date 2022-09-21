using System;
using _153504_Mamchenko_Lab2.Collections;
using _153504_Mamchenko_Lab2.Entities;

namespace _153504_Mamchenko_Lab2 // Note: actual namespace depends on the project name.
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Hotel riga = new Hotel();
            Journal journal = new();
            riga.AddingNotify += journal.RecordEventAddingClientsAndRooms;
            riga.BuyingNotify += (sender, e) => Console.WriteLine($"Описание: {e.Message} Название сущности: {sender?.GetType().Name}");
            riga.AddRoom(2000, 1);
            riga.AddRoom(2000, 2);
            riga.AddRoom(3100, 3);
            riga.AddClient("Ivan");
            riga.AddClient("Petr");
            riga.AddClient("Sidor");
            riga.LogIn("Ivan");
            riga.BuyRoom(2);
            riga.BuyRoom(1);
            riga.LogOut();
            riga.LogIn("Sidor");
            riga.BuyRoom(2);
            riga.BuyRoom(5);
            riga.RemoveRoom(5);
            riga.LogOut();
            riga.LogIn("Pavel");
            riga.ShowFreeRooms();
            try
            {
                Room room4 = new Room(3000, 4);
                riga.RemoveRoom(room4);
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Исключение произошло в методе {ex.TargetSite} объекта {ex.Source} с сообщением: {ex.Message}");

            }
            try
            {
                MyCustomCollection<Client> TestClientsList = new MyCustomCollection<Client>();
                TestClientsList.Add(new Client("Sergey"));
                Console.WriteLine(TestClientsList[2]);
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Исключение произошло в методе {ex.TargetSite} объекта {ex.Source} с сообщением: {ex.Message}");

            }

            journal.OutputEvents();
        }
    }
}
