#include "scanner.h"
#include "token.h"

#include <iostream>

int main()
{
    Scanner s{"if string"};
    std::cout << s.nextToken() << '\n';
    return 0;
}
