using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab4
{
    public class Hotel
    {
        
        private string name;

        private static Hotel? hotelInstance;
        public static Hotel GetHotel(string? name)
        {
            name??= "HotEL";
            
            if (hotelInstance == null)
            {
                hotelInstance = new Hotel(name);
            }
            return hotelInstance;
        }
        

        public string Name
        {
            get { return name; }
            set { name = value; }
        }

        private int occupiedPlaces = 4;

        public int OccupiedPlaces
        {
            get 
            { 
                return occupiedPlaces;
            }
            set { 

                if (value < 0)
                {
                    Console.WriteLine("You entered negative price");
                    occupiedPlaces = 0;
                }
                else
                {
                    occupiedPlaces = value;
                }
                return;
            }
        }

        private int placesAtAll = 10;

        public int PlacesAtAll
        {
            get { return placesAtAll; }
            set {
                if (value < 0)
                {
                    Console.WriteLine("You entered negative price");
                    placesAtAll = 0;
                }
                else if (value < occupiedPlaces)
                {
                    Console.WriteLine("Occupied places can't be more than all places");
                    placesAtAll = occupiedPlaces;
                }
                else
                {
                    placesAtAll = value;
                }
                return;
            }
        }

        public Rate hotelRate = new Rate();

        private Hotel()
        {
            name = "Hotel";
        }

        private Hotel(string name)
        {
            this.name = name;
        }

        public int TotalRate()
        {
            return hotelRate.PriceForDay * occupiedPlaces;
        }

        public int EditRate
        {
            get { return hotelRate.PriceForDay; }
            set
            {
                if (value < 0)
                {
                    Console.WriteLine("You entered negative price");
                    hotelRate.PriceForDay = 0;
                }
                else
                {
                    hotelRate.PriceForDay = value;
                }
                return;
            }
        }

    }
    
}
