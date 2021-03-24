#include "scanner.h"
#include "token.h"
#include "readfile.h"

#include <iostream>
#include <exception>

int main(int argc, char* argv[])
{
    if (argc == 2) {
        std::string contents{readFile(argv[1])};
        std::cout << contents << '\n';
        Scanner s{contents};

        try {

            while (!s.isAtEnd()) {
                std::cout << s.nextToken() << ' ';
            }
        } catch (const std::exception &s) {
            std::cerr << s.what();
        }

        std::cout << "\nend\n";
    }
    return 0;
}
