#ifndef PARSEERROR_H
#define PARSEERROR_H

#include <exception>
#include <string>

class ParseError : public std::exception
{
private:
    std::string m_errmsg;
    size_t m_line_num;

public:
    ParseError(std::string errmsg, size_t line_num)
        : m_line_num{line_num}, m_errmsg{errmsg}
    {
    }

    const char* what() const noexcept override;
};

#endif
