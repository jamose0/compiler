#include "scanner.h"
#include "token.h"

#include <iostream>

int main()
{
    Scanner s{"\n  \t\n 9functst{}ring"};
    std::cout << s.nextToken() << '\n';
    return 0;
}
