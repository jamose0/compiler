#ifndef SCANNEREXCEPTION_H
#define SCANNEREXCEPTION_H

/* ScannerException class
*  ----------------------
*  This class should be
*  thrown on a lexical
*  error
*   ------------------- */

#include <exception>
#include <string>

class ScannerException : public std::exception
{
private:
    std::string m_errmsg;
    size_t m_line_num;

public:
    ScannerException(std::string errmsg, size_t line_num)
        : m_line_num{line_num}
    {
        m_errmsg = errmsg + " at line " + std::to_string(m_line_num) + '\n';
    }

    const char* what() const noexcept override;
};

#endif
