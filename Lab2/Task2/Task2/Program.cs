using System;

Program obj = new Program();
obj.input();

public class Program
{

    public int isInShape(int x, int y)
    {
        if (x * x + y * y < 49 && x * x + y * y > 9)
        {
            Console.WriteLine("Yes");
            return 1;
        }
        else if (x * x + y * y == 49 || x * x + y * y == 9)
        {
            Console.WriteLine("On the border");
            return 2;
        }
        else
        {
            Console.WriteLine("No");
            return 0;
        }
    }
    public void input()
    {
        bool f = true;
        while (f)
        {
            Console.Write("///////MENU///////\nEnter 1 to continue\nOr enter 0 to finish\nField for entering:");
            int a = Convert.ToInt32(Console.ReadLine());

            switch (a)
            {
                case 0:
                    f = false;
                    continue;
                case 1:
                    Console.Write("Enter x: ");
                    int x = Convert.ToInt32(Console.ReadLine());
                    Console.Write("Enter y: ");
                    int y = Convert.ToInt32(Console.ReadLine());

                    isInShape(x, y);
                    break;
                default:
                    Console.WriteLine("Incorrect input!");
                    continue;
            }
        }
    }
}

