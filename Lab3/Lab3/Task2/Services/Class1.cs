using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task2.Services
{
    public class Class1
    {
        public double f1(int z)
        {
            double x;
            if (z < -1)
            {
                x = -z / 3;
                Console.WriteLine("First branch");
            } else
            {
                x = Math.Abs(z);
                Console.WriteLine("Second branch");
            }
            double y = Math.Log(x + 0.5) + (Math.Exp(x) - Math.Exp(-x));
            return y;
        }
    }
}
