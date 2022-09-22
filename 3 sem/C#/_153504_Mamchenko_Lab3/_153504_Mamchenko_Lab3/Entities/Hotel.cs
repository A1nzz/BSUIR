namespace _153504_Mamchenko_Lab3.Entities
{
    public class Hotel
    {

        public delegate void RoomAndClientHandler(Hotel sender, HotelEventArgs e);
        public event RoomAndClientHandler? AddingNotify;

        public delegate void RoomBuyingHandler(Hotel sender, HotelEventArgs e);
        public event RoomAndClientHandler? BuyingNotify;


        private Dictionary<int, Room> roomsList;
        private List<Client> clientsList;
        private Client curClient;


        public Hotel()
        {
            roomsList = new Dictionary<int , Room>();
            clientsList = new List<Client>();
            curClient = new Client("");
        }

        public void AddRoom(int price, int number)
        {
            roomsList.Add(number, new Room(price, number));
            AddingNotify?.Invoke(this, new HotelEventArgs("Добавлена комната номер " + number + "стоимостью " + price));
        }

        public void AddRoom(Room room)
        {
            roomsList.Add(room.Number, room);
            AddingNotify?.Invoke(this, new HotelEventArgs("Добавлена комната номер " + room.Number + "стоимостью " + room.Price));
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

        public List<int> GetSortedListOfRooms()
        {
            var sortedList = from room in roomsList
                                   orderby room.Value.Price
                                   select room.Key;
            return sortedList.ToList();  
        } 

        public void BuyRoom(int numb) 

        {
            if (curClient.Name == "") { BuyingNotify?.Invoke(this, new HotelEventArgs("Вам нужно залогиниться")); return; }
            if (roomsList.ContainsKey(numb))
            {
                if (roomsList[numb].IsFree)
                {
                    curClient.AddRoom(roomsList[numb]);
                    BuyingNotify?.Invoke(this, new HotelEventArgs("Клиент " + curClient.Name + " купил комнату " + numb));
                }
                else
                {
                    BuyingNotify?.Invoke(this, new HotelEventArgs("Комната номер " + numb + " уже куплена"));
                    return;
                }                
            }
            else
            {
                BuyingNotify?.Invoke(this, new HotelEventArgs("Комнаты с номером " + numb + " не существует"));
            }
        }
        
        public int GetGeneralPriceOfAllBookingRooms()
        {

            var price = (from roomItem in roomsList
                         where !roomItem.Value.IsFree
                         select roomItem.Value).Sum(r => r.Price);
            return price;
            //return roomsList.Where(rm => !rm.Value.IsFree).Sum(rm => rm.Value.Price);
        }
        
        public string? GetClientNameWithMaxPriceOfAllRooms()
        {
            return clientsList.MaxBy(client => client.GetTotalPrice())?.Name;
        }

        public int GetClientCountThatPaidMoreThanDefinePrice(int definePrice)
        {
            return clientsList.Count(client => client.GetTotalPrice() > definePrice);
        }

        public IEnumerable<(int price, int coont)> GetListGroupedByPrice()
        {
            return roomsList.GroupBy(room => room.Value.Price).Select(group => (group.Key, group.Count()));
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
