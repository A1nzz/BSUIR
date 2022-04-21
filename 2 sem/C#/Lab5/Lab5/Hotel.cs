namespace Lab5
{
    public class Hotel
    {
        private List<Room> roomsList;
        private List<Client> clientsList;
        private Client curClient;


        public Hotel()
        {
            roomsList = new List<Room>();
            clientsList = new List<Client>();
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
            foreach (Room room in roomsList)
            {
                if (room.Number == numb)
                {
                    if (curClient.BuyRoom)
                    {
                        Console.WriteLine("Клиент уже забронировал одну комнату");
                        return;
                    }
                    else if (room.IsFree)
                    {
                        curClient.BuyRoom = true;
                        curClient.Room = room;
                        room.IsFree = false;
                        Console.WriteLine("Клиент забронировал номер " + room.Number);
                        return;
                    }
                    else if (!room.IsFree)
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
            foreach (Client cl in clientsList)
            {
                if(cl.Name == name)
                {
                    curClient = new Client(name);
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
            foreach (Room room in roomsList)
            {
                if (room.IsFree)
                {
                    Console.WriteLine("Номер " + room.Number + " свободен");
                }
            }
        }

        public int getPriceByName(string name)
        {
            int price = 0;
            foreach (Client cl in clientsList)
            {
                if (cl.Name == name)
                {
                    price = cl.Room.Price;
                }
            }
            return price;
        }
    }
}
