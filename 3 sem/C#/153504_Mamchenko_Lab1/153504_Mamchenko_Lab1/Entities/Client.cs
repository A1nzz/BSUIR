using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Mamchenko_Lab1.Entities
{
    public class Client
    {
        private string? name;
        public string? Name
        {
            get { return name; }
            set { name = value; }
        }

        private Room room;
        public Room Room
        {
            get { return room; }
            set { room = value; }
        }

        public Client(string name)
        {
            this.name = name;
        }

        private bool buyRoom = false;
        public bool BuyRoom
        {
            get { return buyRoom; }
            set { buyRoom = value; }
        }
    }
}
