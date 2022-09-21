using _153504_Mamchenko_Lab2.Collections;

namespace _153504_Mamchenko_Lab2.Entities
{
    public class Hotel
    {

        public delegate void RoomAndClientHandler(Hotel sender, HotelEventArgs e);
        public event RoomAndClientHandler? AddingNotify;

        public delegate void RoomBuyingHandler(Hotel sender, HotelEventArgs e);
        public event RoomAndClientHandler? BuyingNotify;


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
            AddingNotify?.Invoke(this, new HotelEventArgs("Добавлена комната номер " + number + "стоимостью " + price));
        }

        public void AddRoom(Room room)
        {
            roomsList.Add(room);
            AddingNotify?.Invoke(this, new HotelEventArgs("Добавлена комната номер " + room.Number + "стоимостью " + room.Price));
        }

        public void RemoveRoom(int number)
        {
            for(int i = 0; i < roomsList.Count; i++)
            {
                if (roomsList[i]?.Number == number)
                {
                    roomsList.Remove(roomsList[i]);
                    AddingNotify?.Invoke(this, new HotelEventArgs("Убрана комната номер " + number));
                    return;
                }
            }
            AddingNotify?.Invoke(this, new HotelEventArgs($"Комнаты с номером {number} не существует"));
        }

        public void RemoveRoom(Room room)
        {
            roomsList.Remove(room);
            AddingNotify?.Invoke(this, new HotelEventArgs("Убрана комната номер " + room.Number));
        }

        public void AddClient(string name)
        {
            clientsList.Add(new Client(name));
            AddingNotify?.Invoke(this, new HotelEventArgs("Добавлен клиент с именем" + name));
        }

        public void AddClient(Client client)
        {
            clientsList.Add(client);
            AddingNotify?.Invoke(this, new HotelEventArgs("Добавлен клиент с именем" + client.Name));
        }

        public void RemoveClient(string name)
        {
            for (int i = 0; i < clientsList.Count; i++)
            {
                if (clientsList[i]?.Name == name)
                {
                    clientsList.Remove(clientsList[i]);
                    AddingNotify?.Invoke(this, new HotelEventArgs("Убран клиент с именем" + name));
                    return;
                }
            }
            AddingNotify?.Invoke(this, new HotelEventArgs($"Клиента с именем {name} не существует"));
        }

        public void RemoveClient(Client client)
        {
            clientsList.Remove(client);
            AddingNotify?.Invoke(this, new HotelEventArgs("Убран клиент с именем" + client.Name));
        }

        public void BuyRoom(int numb)
        {
            foreach (Room room in roomsList)
            {
                if (room.Number == numb)
                {
                    if (curClient.BuyRoom)
                    {
                        BuyingNotify?.Invoke(this, new HotelEventArgs("Клиент уже забронировал одну комнату"));
                        Console.WriteLine("Клиент уже забронировал одну комнату");
                        return;
                    }
                    else if (room.IsFree)
                    {
                        curClient.BuyRoom = true;
                        curClient.Room = room;
                        room.IsFree = false;
                        BuyingNotify?.Invoke(this, new HotelEventArgs("Клиент забронировал номер " + room.Number));
                        Console.WriteLine("Клиент забронировал номер " + room.Number);
                        return;
                    }
                    else if (!room.IsFree)
                    {
                        BuyingNotify?.Invoke(this, new HotelEventArgs($"Номер {room.Number} уже забронирован"));
                        Console.WriteLine("Номер уже забронирован");
                        return;
                    }
                }
            }
            BuyingNotify?.Invoke(this, new HotelEventArgs("Комната с таким номером не существует"));
            Console.WriteLine("Номера с таким номером не существует");
        }

        public void LogIn(string name)
        {
            foreach (Client cl in clientsList)
            {
                if(cl.Name == name)
                {
                    curClient = cl;
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
    public class HotelEventArgs : EventArgs
    {
        public string Message { get; }
        public HotelEventArgs(string message)
        {
            Message = message;
        }
    }

}
