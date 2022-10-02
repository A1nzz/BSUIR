using _153504_Mamchenko_Lab5.Domain.Entities;
using Serialize;
namespace _153504_Mamchenko_Lab5
{
    class Program
    {
        static void Main(string[] args)
        {
            List<Restaurant> listOfRestaurants = new List<Restaurant>();
            listOfRestaurants.Add(new Restaurant("Riga", new Kitchen("Ukranian", 120)));
            listOfRestaurants.Add(new Restaurant("Hinkalnaya", new Kitchen("Georgian", 140)));
            listOfRestaurants.Add(new Restaurant("McDonalds", new Kitchen("American", 100)));
            listOfRestaurants.Add(new Restaurant("KFC", new Kitchen("American", 150)));
            listOfRestaurants.Add(new Restaurant("Vasilki", new Kitchen("Belarusian", 108)));

            var serializer = new Serializer();
            serializer.SerializeJSON(listOfRestaurants, "rests.json");


            var listReadedFronJSONFile = serializer?.DeSerializeJSON("rests.json")?.ToList();
            Console.WriteLine("/////JSON:");
            foreach (var item in listReadedFronJSONFile)
            {
                Console.WriteLine($"Name: {item.Name}\nTypeOfKitchen: {item?.Kitchen?.Name}\nArea: {item?.Kitchen?.Area}\n");
            }

            serializer?.SerializeByLINQ(listOfRestaurants, "rests(LINQ).xml");

            var listReadedFronXMLFileWithLINQ = serializer?.DeSerializeByLINQ("rests(LINQ).xml");

            Console.WriteLine("/////XML(LINQ)");
            foreach (var item in listReadedFronXMLFileWithLINQ)
            {
                Console.WriteLine($"Name: {item.Name}\nTypeOfKitchen: {item?.Kitchen?.Name}\nArea: {item?.Kitchen?.Area}\n");
            }

            serializer?.SerializeXML(listOfRestaurants, "rests.xml");

            var listReadedFronXMLFile = serializer?.DeSerializeXML("rests.xml");

            Console.WriteLine("/////Common XML:");
            foreach (var item in listReadedFronXMLFile)
            {
                Console.WriteLine($"Name: {item.Name}\nTypeOfKitchen: {item?.Kitchen?.Name}\nArea: {item?.Kitchen?.Area}\n");
            }
        }
        
    }
}
