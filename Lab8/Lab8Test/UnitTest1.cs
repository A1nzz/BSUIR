using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Lab8
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestAddDiscount()
        {
            double[] arrOfPrices = { 10, 20, 30, 40, 50 };
            double[] arrOfDiscounts = { 10, 20, 30, 40, 50 };
            for (int i =0; i < 5; i++)
            {
                Hotel h = new Hotel();
                h.AddAbsDiscount(101, arrOfPrices[i], arrOfDiscounts[i]);
                Assert.AreEqual(h.GetTotalPrice(), arrOfPrices[i] - arrOfPrices[i] * arrOfDiscounts[i] / 100);
            }
        }
        [TestMethod]
        public void TestAddNoDiscount()
        {
            double[] arrOfPrices = { 10, 20, 30, 40, 50 };
            for (int i = 0; i < 5; i++)
            {
                Hotel h = new Hotel();
                h.AddNoDiscount(101, arrOfPrices[i]);
                Assert.AreEqual(h.GetTotalPrice(), arrOfPrices[i]);
            }
            
        }
    }
}