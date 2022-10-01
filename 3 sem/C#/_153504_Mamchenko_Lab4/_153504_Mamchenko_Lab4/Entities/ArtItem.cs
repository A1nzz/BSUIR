using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Mamchenko_Lab4.Entities
{
    internal class ArtItem
    {
        public string? Name { get; set; }
        public int? Price{get;set;}
        public bool? IsAvailiableToBuy { get; set; }
        
        public ArtItem()
        {
            Price = null;
            IsAvailiableToBuy = null;
            Name = null;
        }
        public ArtItem(string? name, int? price, bool? isAvailiableToBuy)
        {
            Price = price;
            IsAvailiableToBuy = isAvailiableToBuy;
            Name = name;
        }

         public ArtItem(string stringFromFile)
        {
            string[] ArrOfData = stringFromFile.Split(' ');
            Name = ArrOfData[0];
            Price = int.Parse(ArrOfData[1]);
            IsAvailiableToBuy = bool.Parse(ArrOfData[2]);
        }
        public override string ToString()
        {
            return $"{Name} {Price} {IsAvailiableToBuy}";
        }
    }
}
