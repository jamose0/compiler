#ifndef SCANNER_H
#define SCANNER_H

#include "token.h"

#include <string>
#include <string_view>
#include <iostream>

class Scanner
{
private:
    // source string
    const std::string m_src;

    // Pointer to item of string
    char* ip;

    // Consume and return the next character of the source string
    char nextChar();

    // Return but do not consume the next character of the source string
    char peekChar();

    bool matchStr(char* p1, std::string_view p2, int len);

public:
    Scanner(std::string_view src);

    virtual ~Scanner() {}

    Token nextToken();
};

#endif
