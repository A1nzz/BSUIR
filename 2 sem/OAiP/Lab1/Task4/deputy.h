#ifndef DEPUTY_H
#define DEPUTY_H

#include <QString>
#include <string>

class Deputy
{
    friend class MainWindow;
public:
    Deputy(int districtNumber = 13, std::string fullName = "Mamchenko Kirill", std::string party = "Labour",
           int age = 18, std::string profession = "programmer", int incomeYear = 15);
    friend std::istream& operator>>(std::istream&, Deputy&);
    friend std::fstream& operator<<(std::fstream&, Deputy&);
private:
    int m_districtNumber;
    std::string m_fullName;
    std::string m_party;
    int m_age;
    std::string m_profession;
    int m_incomeYear;
};

#endif // DEPUTY_H
