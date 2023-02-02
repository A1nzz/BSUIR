using ClassLib;
using System.Threading;

namespace _153504_Mamchenko_Lab7
{
    class Program
    {
        static void Main(string[] args)
        {

            int y = 1;
            Integral integral = new Integral();
            integral.GetTime += (message) => {
                Console.SetCursorPosition(0,y);
                y++;
                Console.WriteLine(message); 
            };
            Thread myThread1 = new Thread(() => integral.FindIntegral());
            myThread1.Priority = ThreadPriority.Highest;
            myThread1.Start();
            
            Thread myThread2 = new Thread(() => integral.FindIntegral());            
            myThread2.Priority = ThreadPriority.Lowest;
            myThread2.Start();    
            
            Thread myThread3 = new Thread(() => integral.FindIntegral());        
            myThread3.Start();
            
            Thread myThread4 = new Thread(() => integral.FindIntegral());        
            myThread4.Start();

            Thread myThread5 = new Thread(() => integral.FindIntegral());
            myThread5.Start();
            Console.ReadKey(false);

        }
    }
}