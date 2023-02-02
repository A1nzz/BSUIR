using System;
using ClassLib;

namespace _153504_Mamchenko_Lab8 // Note: actual namespace depends on the project name.
{
    internal class Program
    {
        static IProgress<string> progress = new Progress<string>(obj => Console.WriteLine(obj));

        static async Task Main(string[] args)
        {

            Console.WriteLine($"Начало выполнения мэйна, номер потока {Thread.CurrentThread.ManagedThreadId}");

            List<ArtGallery> list = new List<ArtGallery>();

            for (int i = 0; i < 1000000; i++)
            {
                list.Add(new ArtGallery(i, "art" + i, i * 10));
            }

            StreamService<ArtGallery> service = new StreamService<ArtGallery>();

            Stream temp = new MemoryStream();

            Console.WriteLine($"методы 1 и 2 запущены из мэйна, номер потока {Thread.CurrentThread.ManagedThreadId}");

            var task1 = service.WriteToStreamAsync(temp, list, progress);

            await Task.Delay(100);//чтобы первый метод точно запустился первым

            var task2 = service.CopyFromStreamAsync(temp, "input.txt", progress);

            Task.WaitAll(task1, task2);

            int result = await service.GetStatisticsAsync("input.txt", obj => obj.NumberOfWorks > 50 ? true : false);
            Console.WriteLine(result);
        }
    }
}