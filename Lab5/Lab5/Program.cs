/// <summary>
/// Основная программа
/// </summary>
/// 
namespace Lab5
{
    class Program
    {
        static void Main()
        {
            Hotel riga = new Hotel();
            riga.AddRoom(1100, 1);
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
            riga.LogOut();
            riga.LogIn("Pavel");
            Console.WriteLine(riga.getPriceByName("Ivan"));
            riga.ShowFreeRooms();
        }
    }
}

