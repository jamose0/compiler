#include "scanner.h"
#include "token.h"
#include "scannerexception.h"

#include <cstring>

static bool matchStr(char* p1, std::string_view p2, int len)
{
    return (strncmp(p1, p2.data(), len) == 0);
}

Scanner::Scanner(std::string_view src)
    : m_src{src}
{
    m_ip = const_cast<char*>(m_src.data());
    m_line_num = 1;
}

void Scanner::skipWS()
{
    while (*m_ip == ' ' || *m_ip == '\t' || *m_ip == '\n') {
        if (*m_ip == '\n')
            ++m_line_num;
        ++m_ip;
    }
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

    skipWS();
    if (*m_ip == '#') {
        std::cout << "comment\n";
        while (*(m_ip++) != '\n');
        ++m_line_num;
    }
    skipWS();

    char* sp = m_ip;
    // std::cout << character << '\n';


    character = nextChar();
    std::cout << '\n';

    /* Bugfix: I noticed that the 'interface' keyword was being recognized
       as an identifier. This was because the if(checkKW) statement for
       'interface' was below the if(checkKW) statement for 'int'. Since the
       first three characters match, checkKW moved the m_ip pointer. When
       control reached the if(checkKW) for 'interface', the pointer was at
       'e', so it checkKW returned false. To fix this, I reordered many of
       if statements to check the longest string first. I could reimplement
       checkKW to not move the pointer, but this could cause more problems*/
    switch (character) {
        /* We can use getIdent because in each case, the first character
           is a letter */

        // NOTE: Perhaps it would be better if we delegated the token returning
        // responsibility to checkKW...
    case '#': {
        while (*(m_ip++) != '\n');
        break;
    }
    case 'i': {

        if (checkKW("interface")) {
            return MAKE_TOK(INTERFACE, sp, 9);
        }
        if (checkKW("implement")) {
            return MAKE_TOK(IMPLEMENT, sp, 9);
        }
        if (checkKW("import")) {
            return MAKE_TOK(IMPORT, sp, 6);
        }
        if (checkKW("int")) {
            return MAKE_TOK(INT, sp, 3);
        }
        if (checkKW("if")) {
            return MAKE_TOK(IF, sp, 2);
        }
        return getIdent(sp);
    }
    case 'f': {
        if (checkKW("funct")) {
            return MAKE_TOK(FUNCT, sp, 5);
        }
        if (checkKW("for")) {
            return MAKE_TOK(FOR, sp, 3);
        }
        getIdent(sp);
    }
    case 'l':
        return ((checkKW("loop")) ? MAKE_TOK(LOOP, sp, 4) : getIdent(sp));
    case 'v': {
        return (checkKW("var") ? MAKE_TOK(VAR, sp, 3) : getIdent(sp));
        /* Check for keyword "var" */
        //if (checkKW("var")) {
        //std::cout << "FOUND VAR!\n";
        //return Token{TokenType::VAR, std::string{sp, 3}};
        //}
        //break;
    }
    case 'c': {
        if (checkKW("continue")) {
            return MAKE_TOK(CONTINUE, sp, 8);
        }
        if (checkKW("class")) {
            return MAKE_TOK(CONTINUE, sp, 5);
        }
        return getIdent(sp);
    }
    case 'r': {
        if (checkKW("return")) {
            return MAKE_TOK(RETURN, sp, 6);
        }
        if (checkKW("real")) {
            return MAKE_TOK(REAL, sp, 4);
        }
        return getIdent(sp);
    }
    case 'e':
        return ((checkKW("else")) ? MAKE_TOK(ELSE, sp, 4) : getIdent(sp));
    case 'm':
        return ((checkKW("match")) ? MAKE_TOK(MATCH, sp, 5) : getIdent(sp));
    case 's':
        return ((checkKW("string")) ? MAKE_TOK(STRING, sp, 6) : getIdent(sp));
    case 'p':
        return ((checkKW("pub")) ? MAKE_TOK(PUB, sp, 3) : getIdent(sp));
    case '}': return MAKE_TOK(R_BRACE, sp, 1);
        /* make the rest of these use MAKE_TOK */
    case '{': return MAKE_TOK(L_BRACE, sp, 1);
    case ']': return MAKE_TOK(R_SQUARE, sp, 1);
    case '[': return MAKE_TOK(L_SQUARE, sp, 1);
    case ')': return MAKE_TOK(R_PAREN, sp, 1);
    case '(': return MAKE_TOK(L_PAREN, sp, 1);
    case ';': return MAKE_TOK(SEMICOLON, sp, 1);
    case ':': return MAKE_TOK(COLON, sp, 1);
    case ',': return MAKE_TOK(COMMA, sp, 1);
    case '*': return MAKE_TOK(STAR, sp, 1);
    case '/': return MAKE_TOK(SLASH, sp, 1);
    case '+': return MAKE_TOK(PLUS, sp, 1);
    case '-': return MAKE_TOK(MINUS, sp, 1);
    case '.': return MAKE_TOK(DOT, sp, 1);
    case '=': {
        if (*m_ip == '=') {
            nextChar();
            return MAKE_TOK(EQ_EQ, sp, 2);
        } else {
            return MAKE_TOK(EQ, sp, 1);
        }
    }
    case '!': {
        if (*m_ip == '=') {
            nextChar();
            return MAKE_TOK(BANG_EQ, sp, 2);
        } else {
            return MAKE_TOK(BANG, sp, 1);
        }
    }
    case '>': {
        if (*m_ip == '=') {
            nextChar();
            return MAKE_TOK(GREATER_EQ, sp, 2);
        } else {
            return MAKE_TOK(GREATER, sp, 1);
        }
    }
    case '<': {
        if (*m_ip == '=') {
            nextChar();
            return MAKE_TOK(LESS_EQ, sp, 2);
        } else {
            return MAKE_TOK(LESS, sp, 1);
        }
    }
    case '"': {
        while (*m_ip != '"') {
            if (*m_ip == '\n') {
                ++m_line_num;
            }

            if (isAtEnd()) {
                throw ScannerException{"Unmatched quote", m_line_num};
            }
            nextChar();
        }
        nextChar();

        return MAKE_TOK(STR_L, sp + 1, static_cast<size_t>(m_ip - sp - 2));
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

    if (character == EOF || character == '\0') {
        std::cout << "eof\n";
    }

    throw(ScannerException{"Unexpected symbol '" +
            std::string{sp, 1} + "'", m_line_num});
    return Token{TokenType::ERROR, std::string{"err"}};
}
