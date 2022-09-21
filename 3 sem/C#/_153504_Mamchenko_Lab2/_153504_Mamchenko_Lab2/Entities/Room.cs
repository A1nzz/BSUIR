using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Mamchenko_Lab2.Entities
{
    public class Room
    {
        private bool isFree = true;
        public bool IsFree
        {
            get { return isFree; }
            set { isFree = value; }
        }

        private int price;
        public int Price
        {
            get { return price; }
            set { price = value; }
        }

        private int number;
        public int Number
        {
            get { return number; }
            set { number = value; }
        }

        public Room(int price, int number)
        {
            this.price = price;
            this.number = number;
        }
    }
}
