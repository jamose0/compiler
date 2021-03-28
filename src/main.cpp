#include "scanner.h"
#include "token.h"
#include "readfile.h"
#include "parser.h"

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
    Parser p{"if !>= { var x = 7; var y = 9; }"};
    p.parse();
    return 0;
}
