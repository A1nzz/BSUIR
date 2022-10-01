using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _153504_Mamchenko_Lab4.Entities;

namespace _153504_Mamchenko_Lab4.MyCustomCollections
{
    internal class MyCustomComparer<T> : IComparer<T>
    {
        public int Compare(T? x, T? y)
        {
            if (x == null && y == null)
                return 0;
            if (x == null)
                return -1;
            if (y == null)
                return 1;
            string? strX = x.ToString();
            string[] ArrOfDataX = strX!.Split(' ');
            string? NameX = ArrOfDataX[0];
            string? strY = y.ToString();
            string[] ArrOfDataY = strY!.Split(' ');
            string? NameY = ArrOfDataY[0];
            return NameX.CompareTo(NameY);
        }
    }
}
