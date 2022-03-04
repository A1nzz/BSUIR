#include "deputy.h"

Deputy::Deputy(int districtNumber, std::string fullName, std::string party, int age, std::string profession, int incomeYear)
{
    m_districtNumber = districtNumber;
    m_fullName = fullName;
    m_party = party;
    m_age = age;
    m_profession = profession;
    m_incomeYear = incomeYear;
}
