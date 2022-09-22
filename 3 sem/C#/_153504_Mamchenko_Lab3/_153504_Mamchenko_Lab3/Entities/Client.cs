using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Mamchenko_Lab3.Entities
{
    public class Client
    {
        private string? _name;
        public string? Name
        {
            get { return _name; }
            set { _name = value; }
        }

        private List<Room> _roomsList = new List<Room>();

        public void AddRoom(Room room)
        {
            _roomsList?.Add(room);
            room.IsFree = false;
        }

        public int GetTotalPrice()
        {
            return _roomsList.Sum(item => item.Price);
        }

        public Client(string name)
        {
            this._name = name;
        }

        private bool buyRoom = false;
        public bool BuyRoom
        {
            get { return buyRoom; }
            set { buyRoom = value; }
        }
    }
}
