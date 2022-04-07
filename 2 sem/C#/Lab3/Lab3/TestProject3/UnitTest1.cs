using Microsoft.VisualStudio.TestTools.UnitTesting;
using Task3;

namespace TestProject3
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestDayOfWeek2()
        {
            string[] s = {"30.03.2022", "31.03.2022" };
            string[] sD = {"Wednesday" ,"Thursday" };
            DateService obj = new Task3.DateService();
            for (int i = 0; i  < 2; i++)
            {
                Assert.AreEqual(sD[i], obj.GetDay(s[i]));
            }
            
        }
        [TestMethod]
        public void TestSpan()
        {
            DateService obj = new Task3.DateService();
            System.DateTime d = System.DateTime.Today;
            System.DateTime dcur = new System.DateTime(2022, 03, 20);
            Assert.AreEqual((int)System.Math.Abs((d - dcur).TotalDays), obj.GetDaysSpan(20, 03, 2022));
        }
        [TestMethod]
        public void TestSpan2()
        {

            DateService obj = new Task3.DateService();
            System.DateTime d = System.DateTime.Today;
            System.DateTime dcur = new System.DateTime(2022, 02, 20);
            Assert.AreEqual((int)System.Math.Abs((d - dcur).TotalDays), obj.GetDaysSpan(20, 02, 2022));
        }
    }
}
