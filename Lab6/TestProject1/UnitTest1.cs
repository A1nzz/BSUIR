using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Lab6
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestTotalSumCar()
        {
            Toys car = new Car("BMW", 20000, 2);
            Assert.AreEqual(car.getTotalSum(), 40000);
        }
        [TestMethod]
        public void TestTotalSumDoll()
        {
            Toys doll = new Doll("Ulia", "female", 1200, 5);
            Assert.AreEqual(doll.getTotalSum(), 6000);
        }
        [TestMethod]
        public void TestTotalSumLego()
        {
            Toys legoPolice = new Lego("Lego City", 120, 1400, 9);
            Assert.AreEqual(legoPolice.getTotalSum(), 12600);
        }
    }
}