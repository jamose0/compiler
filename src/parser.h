#ifndef PARSER_H
#define PARSER_H

#include <string>

#include "scanner.h"
#include "token.h"

class Parser
{
private:
    Scanner s;
    Token token;

public:
    Parser(std::string_view inp) : s{inp}, token{s.nextToken()}
    {
        std::cout << token << '\n';
    }
    
};

#endif
