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

public:
    Scanner(std::string_view src);
    //    : m_src{src}
    //{
    //   ip = const_cast<char*>(m_src.data());
    //}

    virtual ~Scanner() {}
};

#endif
