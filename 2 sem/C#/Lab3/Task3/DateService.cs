using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task3
{
    public class DateService
    {
        public string GetDay(string date)
        {
            string yearStr = date;
            yearStr = yearStr.Remove(0, 6);
            int year = Convert.ToInt32(yearStr);

            string monthStr = date;
            monthStr = monthStr.Remove(0, 3);
            monthStr = monthStr.Remove(2,5);
            int month = Convert.ToInt32(monthStr);

            string dayStr = date;
            dayStr = dayStr.Remove(2, 8);
            int day = Convert.ToInt32(dayStr);

            DateTime date_ = new DateTime(year, month, day);
            string day_of_week = (date_.DayOfWeek).ToString();
            return day_of_week;
        }

        public int GetDaysSpan(int day, int month, int year)
        {
            DateTime CurrDay = new DateTime(year, month, day);
            DateTime localDate = DateTime.Now;
            int days = (int)Math.Abs((localDate - CurrDay).TotalDays);
            return days;
        }
    }
}
