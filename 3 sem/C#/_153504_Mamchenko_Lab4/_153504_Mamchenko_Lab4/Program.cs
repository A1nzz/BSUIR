using System;
using _153504_Mamchenko_Lab4.Entities;
using _153504_Mamchenko_Lab4.MyCustomCollections;

namespace _153504_Mamchenko_Lab4 // Note: actual namespace depends on the project name.
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string path = "../../../DataFiles/ArtItems.dat";
            try
            {
                FileService<ArtItem> service = new FileService<ArtItem>();
                List<ArtItem> listOfItemsToWrite = new List<ArtItem>();
                listOfItemsToWrite.Add(new ArtItem("Picture", 2300, true));
                listOfItemsToWrite.Add(new ArtItem("Icon", 400, false));
                listOfItemsToWrite.Add(new ArtItem("Figure", 1500, true));
                listOfItemsToWrite.Add(new ArtItem("Sculpture", 1600, false));
                listOfItemsToWrite.Add(new ArtItem("Vase", 50, true));
                service.SaveData(listOfItemsToWrite, path);

                string newPath = "../../../DataFiles/NewArtItems.dat";

                File.Delete(newPath);
                File.Move(path, newPath);


                List<ArtItem> ListToRead = new List<ArtItem>();
                ListToRead = service.ReadFile(newPath).ToList();

                var orderedList = ListToRead.OrderBy(x => x, new MyCustomComparer<ArtItem>()).ToList();
                Console.WriteLine("\nDeafault Collection:");
                foreach (var item in listOfItemsToWrite)
                {
                    Console.WriteLine(item);
                }
                
                Console.WriteLine("\nSorted By Name Collection:");
                foreach (var item in orderedList)
                {
                    Console.WriteLine(item);
                }

                var listOrderedByPrice = listOfItemsToWrite.OrderBy(x => x.Price).ToList();
                Console.WriteLine("\nSorted By Price Collection:");
                foreach (var item in listOrderedByPrice)
                {
                    Console.WriteLine(item);
                }

            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
           
        }
    }
}