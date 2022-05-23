using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Lab7
{
    [TestClass]
    public class UnitTest1
    {
        static char[] symbArr1 = { 'a', 'b', 'c', 'd'};
        static char[] symbArr2 = { 'a', 'b', 'c', 'e' };
        static char[] symbArr3 = { 'a', 'b', 'c', 'd', 'e'};
        PlentyOfSymbols obj1 = new PlentyOfSymbols(symbArr1);
        PlentyOfSymbols obj2 = new PlentyOfSymbols(symbArr2);
        PlentyOfSymbols obj3 = new PlentyOfSymbols(symbArr1);

        PlentyOfSymbols obj0 = new PlentyOfSymbols();

        
        [TestMethod]
        public void TestCompare()
        {
            Assert.IsTrue(obj1 == obj3);
        }

        [TestMethod]
        public void TestNotCompare()
        {
            Assert.IsTrue(obj1 != obj2);
        }

        [TestMethod]
        public void TestPlus()
        {
            PlentyOfSymbols newObj = obj1 + obj2;
            PlentyOfSymbols newobj0 = obj0 + obj2;
            PlentyOfSymbols newObj2 = new PlentyOfSymbols(symbArr3);
            Assert.AreEqual(newObj, newObj2);
            Assert.AreEqual(newobj0, obj2);

        }

        [TestMethod]
        public void TestMinus()
        {
            PlentyOfSymbols newObj = obj1 - obj2;
            PlentyOfSymbols newObj0 = obj0 - obj2;

            char[] arr = { 'd' };
            PlentyOfSymbols newObj2 = new PlentyOfSymbols(arr);
            Assert.AreEqual(newObj, newObj2);
            Assert.AreEqual(newObj0, obj0);


        }
        [TestMethod]
        public void TestMultuplication()
        {
            PlentyOfSymbols newObj = obj1 * obj2;
            char[] arr = { 'a', 'b', 'c' };
            PlentyOfSymbols newObj2 = new PlentyOfSymbols(arr);
            Assert.AreEqual(newObj, newObj2);
            PlentyOfSymbols newObj0 = obj0 * obj2;
            Assert.AreEqual(newObj0, obj0);
        }

        [TestMethod]
        public void TestBrackets()
        {
            char symbol1 = obj1[2];
            char symbol2 = obj2[2];
            Assert.AreEqual(symbol1, symbol2);
        }
    }
}