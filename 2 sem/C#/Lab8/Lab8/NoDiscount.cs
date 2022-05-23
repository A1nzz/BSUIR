using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab8
{
    public class NoDiscount : IPrice
    {

        private double Price { get; set; }

        public NoDiscount(double price)
        {
            Price = price;
        }


        public double GetPrice()
        {
            return this.Price;
        }
    }
}
