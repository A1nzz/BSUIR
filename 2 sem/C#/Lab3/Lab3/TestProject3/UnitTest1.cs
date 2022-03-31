using Microsoft.VisualStudio.TestTools.UnitTesting;
using Task3;

namespace TestProject3
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestDayOfWeek()
        {
            DateService obj = new Task3.DateService();
            Assert.AreEqual("Wednesday", obj.GetDay("30.03.2022"));
        }
        [TestMethod]
        public void TestDayOfWeek2()
        {
            DateService obj = new Task3.DateService();
            Assert.AreEqual("Thursday", obj.GetDay("31.03.2022"));
        }
        [TestMethod]
        public void TestSpan()
        {
            DateService obj = new Task3.DateService();
            Assert.AreEqual(11, obj.GetDaysSpan(20, 03, 2022));
        }
        [TestMethod]
        public void TestSpan2()
        {
            DateService obj = new Task3.DateService();
            Assert.AreEqual(39, obj.GetDaysSpan(20, 02, 2022));
        }
    }
}
