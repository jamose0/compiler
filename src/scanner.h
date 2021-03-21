#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <string_view>

class Scanner
{
private:
    const std::string m_src;

public:
    Scanner(std::string_view src)
        : m_src{src}
    {}

    virtual ~Scanner() {}
};

#endif
