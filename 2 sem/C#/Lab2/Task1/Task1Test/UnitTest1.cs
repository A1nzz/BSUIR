using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Task1Test
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void enter_6_3()
        {
            int a = 6;
            int b = 3;
            Program obj = new Program();
            bool expected = true;
            Assert.AreEqual(obj.isDev(a, b), expected);
        }
        [TestMethod]
        public void enter_7_3()
        {
            int a = 7;
            int b = 3;
            Program obj = new Program();
            bool expected = false;
            Assert.AreEqual(obj.isDev(a, b), expected);
        }
    }
}
