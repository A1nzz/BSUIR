#ifndef STAFF_H
#define STAFF_H
#include <QString>
#include <string>

class Staff
{
public:   
    std::string getDay(  std::string date) {
        std::string day;
        unsigned int i = 0;
        while (date[i] != '.') {
            day += date[i];
            i++;
        }
        return day;
    }

    std::string getMonth(  std::string date) {
        std::string month;
        unsigned int i = 0;
        while (date[i] != '.') {
            i++;
        }
        i++;
        while (date[i] != '.') {
            month += date[i];
            i++;
        }
        return month;
    }

    std::string getYear(  std::string date) {
        std::string year;
        unsigned int i = 0;
        while (date[i] != '.') {
            i++;
        }
        i++;
        while (date[i] != '.') {
            i++;
        }
        i++;
        while (i < date.length()) {
            year += date[i];
            i++;
        }
        return year;
    }
    Staff();
public:
    //QString fullname;
    std::string fullname;
    int number;
    std::string post;
    //QString post;
    //QString date;
    std::string date;
    Staff* next;
    Staff* prev;
};

#endif // STAFF_H
