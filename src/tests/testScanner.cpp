#include "../scanner.h"
#include "../token.h"

#include <iostream>
#include <string>

int main()
{
    Scanner s{"#comment\n funct main() : () { print(\"hello, world\"); }"};
    std::cout << "hi\n";
    Token t{s.nextToken()};
    if (t.getLexeme() == "funct"
        && t.getType() == TokenType::FUNCT)
        return 0;

    return 1;
}
