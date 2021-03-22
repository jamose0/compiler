#include "scanner.h"
#include "token.h"

#include <iostream>

int main()
{
    Scanner s{"functstring"};
    std::cout << s.nextToken() << '\n';
    return 0;
}
