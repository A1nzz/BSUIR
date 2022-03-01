#ifndef DEPUTY_H
#define DEPUTY_H

#include <QString>

class Deputy
{
    friend class MainWindow;
public:
    Deputy(int districtNumber = 13, QString fullName = "Mamchenko Kirill", QString party = "Labour",
           int age = 18, QString profession = "programmer", int incomeYear = 15);
private:
    int m_districtNumber;
    QString m_fullName;
    QString m_party;
    int m_age;
    QString m_profession;
    int m_incomeYear;
};

#endif // DEPUTY_H
