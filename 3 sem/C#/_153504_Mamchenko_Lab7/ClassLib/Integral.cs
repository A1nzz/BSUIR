using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace ClassLib
{
    public class Integral
    {
        public delegate void TimeDelegate(long time);
        public event TimeDelegate? GetTime;

        private Semaphore semaphore = new Semaphore(2, 2);

        public double FindIntegral()
        {
            semaphore.WaitOne();
            var watch = new Stopwatch();
            watch.Start();
            double result = 0;
            double step = 0.00000001;
            int progress = 0;
            int lastProgress = 0;
            for (double i = 0; i < 1.0; i += step)
            {
                result += Math.Sin(i) * step;
                
                progress = Convert.ToInt32(i / 1.0*100);
                if (progress != lastProgress)
                {
                    lastProgress = progress;
                    ShowProgress(this, progress);
                }                
            }
            watch.Stop();
            GetTime?.Invoke(watch.ElapsedMilliseconds);
            semaphore.Release();
            return result;
        }
        public void ShowProgress(object sender, int percent)
        {
            Console.SetCursorPosition(0, Thread.CurrentThread.ManagedThreadId);
            int number_of_signs = percent;
            string progress = "[";
            for (int i = 0; i < 100; i++)
            {
                if (i < number_of_signs)
                {
                    progress += "=";
                }
                else if (i == number_of_signs)
                {
                    progress += ">";
                }
                else
                {
                    progress += " ";
                }
            }
            progress += "] ";
            progress += percent.ToString() + "%";
            Console.WriteLine($"Thread {Thread.CurrentThread.ManagedThreadId}:{progress}");
        }
    }
}

