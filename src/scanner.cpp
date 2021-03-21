#include "scanner.h"
#include "token.h"

Scanner::Scanner(std::string_view src)
    : m_src{src}
{
    ip = const_cast<char*>(m_src.data());
}

char Scanner::nextChar()
{
    return *(ip++);
}

char Scanner::peekChar()
{
    return *ip;
}

Token Scanner::nextToken()
{
    return Token{TokenType::IDENTIFIER, "x"};
}
