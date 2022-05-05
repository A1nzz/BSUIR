using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Test
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestSingletoneConstructor()
        {
            Lab4.Hotel[] hotels = new Lab4.Hotel[3];
            hotels[0] = Lab4.Hotel.GetHotel("Holiday Inn");
            hotels[1] = Lab4.Hotel.GetHotel("Hilton");
            hotels[2] = Lab4.Hotel.GetHotel("Marriot");

            string[] strHotels = { "Holiday Inn", "Hilton", "Marriot" };

            for (int i = 0; i < hotels.Length; i++)
            {
                Assert.AreEqual(hotels[i].Name, strHotels[0]);
            }
        }

        [TestMethod]
        public void TestOccupiedPlaces()
        {
            Lab4.Hotel hotel = Lab4.Hotel.GetHotel("Holiday Inn");

            int[] ocPlaces = {4, 3, -1};

            int[] checkOcPl = { 4, 3, 0 };

            int[] ocPl = new int[3];

            for (int i = 0; i < ocPl.Length; i++)
            {
                hotel.OccupiedPlaces = ocPlaces[i];
                ocPl[i] = hotel.OccupiedPlaces;
            }

            for (int i = 0; i < ocPl.Length; i++)
            {
                Assert.AreEqual(ocPl[i], checkOcPl[i]);
            }
        }

        [TestMethod]
        public void TestTotalRate()
        {
            Lab4.Hotel hotel = Lab4.Hotel.GetHotel("Holiday Inn");            
            hotel.OccupiedPlaces = 9;
            hotel.EditRate = 11;
            Assert.AreEqual(hotel.TotalRate(), 99);
        }
    }
}