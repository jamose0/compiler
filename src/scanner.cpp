#include "scanner.h"
#include "token.h"

#include <cstring>

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

bool Scanner::matchStr(char* p1, std::string_view p2, int len) 
{
    if (strncmp(p1, p2.data(), len)  == 0)
        return true;

    return false;
}

Token Scanner::nextToken()
{
    char character = nextChar();
    // std::cout << character << '\n';
    switch (character) {
    case 'i': {
        /* Check for keyword if */
        if (matchStr((ip - 1), "if", 2)) {
            std::cout << "FOUND IF!\n";
        }
        break;
    }
    default:
        std::cout << "NOT IF!\n";
    }
    return Token{TokenType::IDENTIFIER, "x"};
}
