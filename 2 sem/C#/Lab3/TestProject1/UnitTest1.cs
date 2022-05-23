using Microsoft.VisualStudio.TestTools.UnitTesting;

using Task1;
namespace TestProject1
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void in6out3()
        {
            Class1 obj = new Class1();
            Assert.AreEqual(3, obj.f1(6));
        }
        [TestMethod]
        public void in3out6()
        {
            Class1 obj = new Class1();
            Assert.AreEqual(6, obj.f1(3));
        }
    }
}
