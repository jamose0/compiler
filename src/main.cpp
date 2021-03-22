#include "scanner.h"
#include "token.h"

#include <iostream>

int main()
{
    Scanner s{"funct string"};
    std::cout << s.nextToken() << '\n';
    return 0;
}
