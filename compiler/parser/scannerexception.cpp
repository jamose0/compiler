#include "scannerexception.h"

const char* ScannerException::what() const noexcept
{
    return m_errmsg.c_str();
}
