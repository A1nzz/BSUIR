using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab8
{
    public class Room
    {
        IPrice ip;

        private int number;

        public int Number
        {
            get { return number; }
            set { number = value; }
        }
        public Room(int number, IPrice ip)
        {
            this.Number = number;
            this.ip = ip;
        }

        public double GetPrice()
        {
            return ip.GetPrice();
        }
    }
}
