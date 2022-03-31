#ifndef POLISH_H
#define POLISH_H
#include <string>


class Polish
{
private:

    std::string stringIn = "a+b*c+(d*e+f)*g";
    std::string stringOut;
public:
    Polish();
    std::string toPolish();
    int Prior ( char a );
};

#endif // POLISH_H
