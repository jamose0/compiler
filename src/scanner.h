#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <string_view>
#include <iostream>

class Scanner
{
private:
    const std::string m_src;
    char* ip;

    char nextChar();

public:
    Scanner(std::string_view src);

    virtual ~Scanner() {}
};

#endif
