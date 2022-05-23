using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Lab5
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestGetPriceByName()
        {
            string[] clients = { "Kirill", "Alex", "Pavel" };
            Hotel h = new Hotel();  
            for (int i = 0; i < 3; i++)
            {
                h.AddClient(clients[i]);
            }
            h.AddRoom(1100, 1);
            h.AddRoom(2000, 2);
            h.AddRoom(3100, 3);
            int[] prices = { 1100, 2000, 3100 };
            h.LogIn(clients[0]);
            h.BuyRoom(1);
            h.LogOut();
            h.LogIn(clients[1]);
            h.BuyRoom(2);    
            h.LogOut();
            h.LogIn(clients[2]);
            h.BuyRoom(3);
            h.LogOut();
            int price;
            for (int  i = 0; i <3;i++)
            {
                price = h.getPriceByName(clients[i]);
                Assert.AreEqual(price, prices[i]);
            }
            price = h.getPriceByName("Aboba");
            Assert.AreEqual(price, 0);
        }
    }
}