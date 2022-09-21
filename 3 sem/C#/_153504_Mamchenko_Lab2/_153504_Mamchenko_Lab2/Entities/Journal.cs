using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Mamchenko_Lab2.Entities
{
    internal class Journal
    {
        private List<string> _eventsList = new();

        public void RecordEventAddingClientsAndRooms(object sender, HotelEventArgs e) 
        { 
            _eventsList.Add($"Событие №{_eventsList.Count + 1}:\nОписание: {e.Message} Название сущности: {sender?.GetType().Name}\n");
        }

        public void OutputEvents()
        {
            foreach (var item in _eventsList)
            {
                Console.WriteLine(item);
            }
        }
    }
}
