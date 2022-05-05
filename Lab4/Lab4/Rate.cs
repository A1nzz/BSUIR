using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab4
{
    public class Rate
    {
        private int priceForDay;

        public int PriceForDay  
        {
            get { return priceForDay; }
            set { 
                if(value < 0)
                {
                    Console.WriteLine("You entered negative price");
                    priceForDay = 1;
                    return;
                }
                priceForDay = value; 
            }
        }


        public Rate()
        {
            priceForDay = 10;
        }

        public Rate(int priceForDay)
        {
            this.priceForDay = priceForDay;
        }
        
    }
}
