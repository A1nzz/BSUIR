#include "polish.h"
#include "stack.h"

Polish::Polish()
{

}

std::string Polish::toPolish()
{
    Stack t[255];
    Stack op[255];
    int k = 0;
    int l = 0;
    while (stringIn[k] != '\0') {
        if (stringIn[k] == ')') {
            while ( (op[]) != '(' ) { // до открывающей скобки

            Op = OutS(Op,&a); // Считываем элемент из стека

            if ( !Op ) a = '\0';

            Out[l++] = a; // и записываем в строку Out.
        }
    }
}

int Polish::Prior(char a)
{
    switch ( a ) {
    case '*': case '/': return 3;

    case '-': case '+': return 2;

    case '(': return 1;
    }
    return 0;

}

