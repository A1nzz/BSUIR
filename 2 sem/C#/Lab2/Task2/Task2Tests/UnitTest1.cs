using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Task2Tests
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void enter_5_0()
        {
            Program obj = new Program();

            Assert.AreEqual(obj.isInShape(5,0), 1);


        }
        [TestMethod]
        public void enter_3_0()
        {
            Program obj = new Program();

            Assert.AreEqual(obj.isInShape(3, 0), 2);
        }
        [TestMethod]
        public void enter_5_5()
        {
            Program obj = new Program();

            Assert.AreEqual(obj.isInShape(5, 5), 0);


        }
    }
}
