using System;




    Program obj = new Program();

    obj.input();
    public class Program
    {

        public bool isDev(int M, int N)
        {
            if (M % N == 0)
            {
                Console.WriteLine("The number M is divisible by N without remainder\nThe quotient of the division is {0}", M / N);
                return true;
            }
            else
            {
                Console.WriteLine("M is not completely divisible by N");
                return false;
            }

        }
        public void input()
        {
            bool f = true;
            while (f)
            {
                Console.Write("///////MENU///////\nEnter 1 to continue\nOr enter 0 to finish\nField for entering:");
                int a = Convert.ToInt32(Console.ReadLine());

                switch (a) {
                    case 0:
                        f = false;
                        continue;

                    case 1:
                    Console.WriteLine("Enter M number: ");
                    int M = Convert.ToInt32(Console.ReadLine());
                    Console.WriteLine("Enter N number: ");
                    int N = Convert.ToInt32(Console.ReadLine());
                    isDev(M, N);
                        break;
                    default:
                        Console.WriteLine("Incorrect input!");
                        continue;
                }

            }
        }
    }

