using Microsoft.VisualStudio.TestTools.UnitTesting;

using Task2.Services;

namespace TestProject2
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void in3_out21()
        {
            Class1 obj = new Task2.Services.Class1();
            Assert.AreEqual(21.288512823315173, obj.f1(3));
        }
        [TestMethod]
        public void in_minus1__out2_75()
        {
            Class1 obj = new Task2.Services.Class1();
            Assert.AreEqual(2.7558674953957674, obj.f1(-1));
        }
        [TestMethod]
        public void in_minus3__out2_75()
        {
            Class1 obj = new Task2.Services.Class1();
            Assert.AreEqual(2.7558674953957674, obj.f1(-3));
        }

    }
}
