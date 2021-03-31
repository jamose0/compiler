#include "scanner.h"
#include "token.h"
#include "readfile.h"
#include "parser.h"
#include "parseerror.h"

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
    Parser p{"while x == --10 {\n  if x == y {\n var x = 7 + 4;}}"};
    try {
        p.parse();
    } catch (const ParseError &err) {
        std::cerr << err.what();
        std::cerr << "Compilation failed: Exiting...\n";
        std::exit(1);
    }
    return 0;
}
