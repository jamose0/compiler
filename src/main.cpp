#include "scanner.h"
#include "token.h"

#include <iostream>

int main()
{
    Scanner s{"return string"};
    std::cout << s.nextToken() << '\n';
    return 0;
}
