#include "polish.h"
#include "stack.h"

Polish::Polish()
{

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

