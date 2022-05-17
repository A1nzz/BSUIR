using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab8
{
    public class Hotel
    {
        List<Room> LstRoom;
        public Hotel()
        {
            LstRoom = new List<Room>();
        }
        public void AddAbsDiscount(int num, double price ,double discount)
        {
            IPrice ip = new AbsDiscount(discount, price);
            LstRoom.Add(new Room(num, ip));
        }

        public void AddNoDiscount(int number, double price)
        {
            IPrice ip = new NoDiscount(price);
            LstRoom.Add(new Room(number, ip));
        }

        public double GetTotalPrice()
        {
            double sum = 0;
            foreach (Room r in LstRoom)
            {
                sum += r.GetPrice();
            }
            return sum;
        }
    }
}
