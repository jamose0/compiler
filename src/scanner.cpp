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

char Scanner::rollBack()
{
    return *(--m_ip);
}

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
    }
    std::cout << "returning false...\n";

    return false;
}

Token Scanner::getIdent(char* sp)
{
    while (isEligibleForIdent())
        nextChar();

    return Token{TokenType::IDENTIFIER,
        std::string{sp, static_cast<size_t>(m_ip - sp)}};
}

Token Scanner::getNumber(char* sp)
{
    while (isdigit(nextChar()));

    rollBack();

    if (peekChar() == '.') {
        std::cout << "float\n";

        nextChar();

        while (isdigit(nextChar()));

        rollBack();

        return Token{TokenType::FLOATING_L,
            std::string{sp, static_cast<size_t>(m_ip - sp)}};
    }

    return Token{TokenType::INTEGER_L,
        std::string{sp, static_cast<size_t>(m_ip - sp)}};
}

bool Scanner::isAtEnd()
{
    return (*m_ip == '\0' || *m_ip == EOF);
}

Token Scanner::nextToken()
{
    char character{};

    while (*m_ip == ' ' || *m_ip == '\t' || *m_ip == '\n') {
        ++m_ip;
    }
    char* sp = m_ip;
    // std::cout << character << '\n';


    character = nextChar();
    std::cout << '\n';

    //if (character == EOF || character == '\0') {
    //   return Token{TokenType::EOF, "end"};
    //}
    //std::cout << character << '\n';
    switch (character) {
    case 'i': {
        if (checkKW("if")) {
            std::cout << "Found if!\n";
            return Token{TokenType::IF, std::string{sp, 2}};
        }

        if (checkKW("int")) {
            std::cout << "FOUND INT!\n";
            return Token{TokenType::INT, std::string{sp, 3}};
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
    case 'v': {
        /* Check for keyword "var" */
        if (checkKW("var")) {
            std::cout << "FOUND VAR!\n";
            return Token{TokenType::VAR, std::string{sp, 3}};
        }
        break;
    }
    case 'c': {
        if (checkKW("class")) {
            std::cout << "FOUND CLASS!\n";
            return Token{TokenType::CLASS, std::string{sp, 5}};
        }

        if (checkKW("continue")) {
            std::cout << "FOUND CONTINUE!\n";
            return Token{TokenType::CONTINUE, std::string{sp, 8}};
        }

        break;
    }
    case 'r': {
        if (checkKW("return")) {
            std::cout << "FOUND RETURN!\n";
            return Token{TokenType::RETURN, std::string{sp, 6}};
        }

        if (checkKW("real")) {
            std::cout << "FOUND REAL!\n";
            return Token{TokenType::REAL, std::string{sp, 4}};
        }

        break;
    }
    case 'e': {
        if (checkKW("else")) {
            std::cout << "FOUND ELSE!\n";
            return Token{TokenType::ELSE, std::string{sp, 4}};
        }

        break;
    }
    case 'm': {
        if (checkKW("match")) {
            std::cout << "FOUND MATCH!\n";
            return Token{TokenType::MATCH, std::string{sp, 5}};
        }
        break;
    }
    case 's': {
        if (checkKW("string")) {
            std::cout << "FOUND STRING!\n";
            return Token{TokenType::STRING, std::string{sp, 6}};
        }
        break;
    }
    case '}': return Token{TokenType::R_BRACE, std::string{character}};
    case '{': return Token{TokenType::L_BRACE, std::string{character}};
    case ']': return Token{TokenType::R_SQUARE, std::string{character}};
    case '[': return Token{TokenType::L_SQUARE, std::string{character}};
    case ')': return Token{TokenType::R_PAREN, std::string{character}};
    case '(': return Token{TokenType::L_PAREN, std::string{character}};
    case ';': return Token{TokenType::SEMICOLON, std::string{character}};
    case ':': return Token{TokenType::COLON, std::string{character}};
    case ',': return Token{TokenType::COMMA, std::string{character}};
    case '*': return Token{TokenType::STAR, std::string{character}};
    case '/': return Token{TokenType::SLASH, std::string{character}};
    case '+': return Token{TokenType::PLUS, std::string{character}};
    case '-': return Token{TokenType::MINUS, std::string{character}};
    case '.': return Token{TokenType::DOT, std::string{character}};
    case '=': {
        if (*m_ip == '=') {
            nextChar();
            return Token{TokenType::EQ_EQ, std::string{(m_ip - 2), 2}};
        } else {
            return Token{TokenType::EQ, std::string{character}};
        }
    }
    case '!': {
        if (*m_ip == '=') {
            nextChar();
            return Token{TokenType::BANG_EQ, std::string{(m_ip - 2), 2}};
        } else {
            return Token{TokenType::BANG, std::string{character}};
        }
    }
    case '>': {
        if (*m_ip == '=') {
            nextChar();
            return Token{TokenType::GREATER_EQ, std::string{(m_ip - 2), 2}};
        } else {
            return Token{TokenType::GREATER, std::string{character}};
        }
    }
    case '<': {
        if (*m_ip == '=') {
            nextChar();
            return Token{TokenType::LESS_EQ, std::string{(m_ip - 2), 2}};
        } else {
            return Token{TokenType::LESS, std::string{character}};
        }
    }
    case '"': {
        while (*m_ip != '"') {

            if (isAtEnd()) {
                return Token{TokenType::ERROR, std::string{"Unmatched paren."}};
            }
            nextChar();
        }
        nextChar();

        return Token{TokenType::STR_L,
            std::string{(sp + 1), static_cast<size_t>(m_ip - sp - 2)}};
    }
    default: {
        std::cout << "NOT KW!\n";
        if (isalpha(character) || character == '_') {
            std::cout << "BEGINNING OF IDENT\n";
        }
        break;
    }
    }

    if (isalpha(character) || character == '_') {
        std::cout << "Beginning of ident\n";

        return getIdent(sp);
    }

    if (isdigit(character)) {
        std::cout << "expecting number\n";

        return getNumber(sp);
    }

    return Token{TokenType::ERROR, std::string{"err"}};
}
