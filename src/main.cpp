#include "scanner.h"
#include "token.h"

#include <iostream>

int main()
{
    Scanner s{"loopestring"};
    std::cout << s.nextToken() << '\n';
    return 0;
}
