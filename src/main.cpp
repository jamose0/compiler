#include "scanner.h"
#include "token.h"

#include <iostream>

int main()
{
    Scanner s{"\n  \t\n return string"};
    std::cout << s.nextToken() << '\n';
    return 0;
}
