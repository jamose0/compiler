#include "parseerror.h"

const char* ParseError::what() const noexcept
{
    return m_errmsg.c_str();
}
