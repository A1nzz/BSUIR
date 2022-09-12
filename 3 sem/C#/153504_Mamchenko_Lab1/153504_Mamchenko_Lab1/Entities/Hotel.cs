using _153504_Mamchenko_Lab1.Collections;

namespace _153504_Mamchenko_Lab1.Entities
{
    public class Hotel
    {
        private MyCustomCollection<Room> roomsList;
        private MyCustomCollection<Client> clientsList;
        private Client curClient;


        public Hotel()
        {
            roomsList = new MyCustomCollection<Room>();
            clientsList = new MyCustomCollection<Client>();
            curClient = new Client("");
        }

        public void AddRoom(int price, int number)
        {
            roomsList.Add(new Room(price, number));
        }

        public void AddClient(string name)
        {
            clientsList.Add(new Client(name));
        }

        public void BuyRoom(int numb)
        {
            for (int i = 0; i < roomsList.Count; i++)
            {
                if (roomsList[i].Number == numb)
                {
                    if (curClient.BuyRoom)
                    {
                        Console.WriteLine("Клиент уже забронировал одну комнату");
                        return;
                    }
                    else if (roomsList[i].IsFree)
                    {
                        curClient.BuyRoom = true;
                        curClient.Room = roomsList[i];
                        roomsList[i].IsFree = false;
                        Console.WriteLine("Клиент забронировал номер " + roomsList[i].Number);
                        return;
                    }
                    else if (!roomsList[i].IsFree)
                    {
                        Console.WriteLine("Номер уже забронирован");
                        return;
                    }
                }
            }
            Console.WriteLine("Номера с таким номером не существует");
        }

        public void LogIn(string name)
        {
            for (int i = 0; i< clientsList.Count; i++)
            {
                if(clientsList[i].Name == name)
                {
                    curClient = clientsList[i];
                    return;
                }
            }
            Console.WriteLine("Пользователь не зарегестрирован");
        }

        public void LogOut()
        {
            curClient = new Client("");
        }

        public void ShowFreeRooms()
        {
            for (int i = 0; i < roomsList.Count; i++)
            {
                if (roomsList[i].IsFree)
                {
                    Console.WriteLine("Номер " + roomsList[i].Number + " свободен");
                }
            }
        }

        public int getPriceByName(string name)
        {
            int price = 0;
            for (int i = 0; i < clientsList.Count; i++)
            {
                if (clientsList[i].Name == name)
                {
                    price = clientsList[i].Room.Price;
                }
            }
            return price;
        }
    }
}
