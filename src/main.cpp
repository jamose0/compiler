#include "scanner.h"
#include "token.h"
#include "readfile.h"

#include <iostream>

int main(int argc, char* argv[])
{
    if (argc == 2) {
        std::string contents{readFile(argv[1])};
        std::cout << contents << '\n';
        Scanner s{contents};

        while (!s.isAtEnd()) {
            std::cout << s.nextToken() << ' ';
        }

        std::cout << "\nend\n";
    }
    return 0;
}
