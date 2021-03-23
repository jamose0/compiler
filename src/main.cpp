#include "scanner.h"
#include "token.h"

#include <iostream>

int main(int argc, char* argv[])
{
    if (argc == 2) {
        Scanner s{argv[1]};

        while (!s.isAtEnd()) {
            std::cout << s.nextToken() << ' ';
        }

        std::cout << "\nend\n";
    }
    return 0;
}
