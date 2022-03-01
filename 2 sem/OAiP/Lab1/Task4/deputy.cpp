#include "deputy.h"

Deputy::Deputy(int districtNumber, QString fullName, QString party, int age, QString profession, int incomeYear)
{
    m_districtNumber = districtNumber;
    m_fullName = fullName;
    m_party = party;
    m_age = age;
    m_profession = profession;
    m_incomeYear = incomeYear;
}
