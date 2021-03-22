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

bool Scanner::isEligibleForIdent(char* ip)
{
    return isalpha(*ip) || isdigit(*ip) || *ip == '_';
}

Token Scanner::nextToken()
{
    char character{};
    char* sp = ip;
    // std::cout << character << '\n';

    for (;;) {
        character = nextChar();
        std::cout << character << '\n';
        switch (character) {
        case 'i': {
            /* Check for keyword if */
            if (matchStr((ip - 1), "if", 2)) {
                std::cout << "FOUND IF!\n";
                /* Move ip to the spot right after the last character
                  of the keyword */
                ip += 1;

                /* If the character that ip is pointing to is an eligible
                 character for an identifier, break because it is an
                identifier */
                if (isEligibleForIdent(ip)) {
                    break;
                }
                return Token{TokenType::IF, std::string{sp, 2}};
            }
            break;
        }
        case 'f': {
            /* Check for keyword "for" */
            if (matchStr((ip - 1), "for", 3)) {
                std::cout << "FOUND FOR!\n";

                ip += 2;

                if (isEligibleForIdent(ip)) {
                    break;
                }

                return Token{TokenType::FOR, std::string{sp, 3}};
            }

            if (matchStr((ip - 1), "funct", 5)) {
                std::cout << "FOUND FUNCT\n";

                ip += 4;

                if (isEligibleForIdent(ip)) {
                    break;
                }

                return Token{TokenType::FOR, std::string{sp, 5}};
            }
            break;
        }
        case 'l': {
            /* Check for keyword loop */
            if (matchStr((ip - 1), "loop", 4)) {
                std::cout << "FOUND LOOP!\n";

                ip += 3;

                if (isEligibleForIdent(ip)) {
                    break;
                }
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
