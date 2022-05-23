using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab8
{
    public class AbsDiscount : IPrice
    {
        private double discount;
        private double Price { get; set; }

        public AbsDiscount(double discount, double price)
        {
            this.discount = discount;
            this.Price = price;
        }

        public double GetPrice() {
            return Price - Price*discount / 100;
        }
    }
}
