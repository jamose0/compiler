#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <iostream>
#include <string_view>

enum class TokenType {
    IF,
    WHILE,
    LOOP,
    IDENTIFIER,
    INTEGER,
    REAL,
    FUNCT,
};

class Token
{
private:
    TokenType m_type;
    const std::string m_lexeme;

public:
    Token(TokenType type, std::string_view lexeme)
        : m_type{type}, m_lexeme{lexeme}
    {}

    TokenType getType();

    std::string_view getLexeme();

    virtual ~Token() {}

    friend std::ostream& operator<<(std::ostream& out, const Token &t);
};

#endif
