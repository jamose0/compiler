#ifndef SCANNER_H
#define SCANNER_H

#include "token.h"

#include <string>
#include <string_view>
#include <iostream>

class Scanner
{
private:
    const std::string m_src;
    char* ip;

    char nextChar();
    char peekChar();

public:
    Scanner(std::string_view src);

    virtual ~Scanner() {}

    Token nextToken();
};

#endif
