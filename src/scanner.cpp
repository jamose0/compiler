#include "scanner.h"
#include "token.h"

#include <cstring>

static bool matchStr(char* p1, std::string_view p2, int len)
{
    return (strncmp(p1, p2.data(), len) == 0);
}

Scanner::Scanner(std::string_view src)
    : m_src{src}
{
    m_ip = const_cast<char*>(m_src.data());
}

char Scanner::nextChar()
{
    return *(m_ip++);
}

char Scanner::peekChar()
{
    return *m_ip;
}

//bool Scanner::matchStr(char* p1, std::string_view p2, int len) 
//{
//if (strncmp(p1, p2.data(), len)  == 0)
//return true;

//return false;
//}

bool Scanner::isEligibleForIdent()
{
    return isalpha(*m_ip) || isdigit(*m_ip) || *m_ip == '_';
}

bool Scanner::checkKW(std::string_view kw)
{
    std::cout << "checking...\n";
    if (matchStr((m_ip - 1), kw, kw.length())) {
        m_ip += kw.length() - 1;

        std::cout << "matched\n";

        return !isEligibleForIdent();

        //if (isEligibleForIdent(*ip))
        //    return false;
        //return true;
    }
    std::cout << "returning false...\n";

    return false;
}

Token Scanner::nextToken()
{
    char character{};
    char* sp = m_ip;
    // std::cout << character << '\n';

    for (;;) {
        character = nextChar();
        std::cout << character << '\n';
        switch (character) {
        case 'i': {
            if (checkKW("if")) {
                std::cout << "Found if!\n";
                return Token{TokenType::IF, std::string{sp, 2}};
            }
            break;
        }
        case 'f': {
            /* Check for keyword "for" */
            if (checkKW("for")) {
                std::cout << "FOUND FOR!\n";
                return Token{TokenType::FOR, std::string{sp, 3}};
            }

            if (checkKW("funct")) {
                std::cout << "FOUND FUNCT\n";
                return Token{TokenType::FUNCT, std::string{sp, 5}};
            }
            break;
        }
        case 'l': {
            /* Check for keyword loop */
            if (checkKW("loop")) {
                std::cout << "FOUND LOOP!\n";
                return Token{TokenType::LOOP, std::string{sp, 4}};
            }
            break;
        }
        default: {
            std::cout << "NOT KW!\n";
            if (isalpha(character) || character == '_') {
                std::cout << "BEGINNING OF IDENT\n";
            }
        }
        }
        break;
    }
    return Token{TokenType::IDENTIFIER, "x"};
}
