#include "scanner.h"
#include "token.h"

#include <iostream>

int main()
{
    Scanner s{"\n  \t\n 83 string fun"};
    std::cout << s.nextToken()
              << ' ' << s.nextToken()
              << ' ' << s.nextToken() << '\n';
    return 0;
}
