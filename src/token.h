#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <iostream>
#include <string_view>

/* List of keywords
 * if
 * for
 * while
 * loop
 * funct
 * var
 * class
 * break
 * continue
 * int
 * real
 * return
 * else
 * match
 * string
 */

enum class TokenType {
    /* Keywords (listed above) */
    IF,
    FOR,
    WHILE,
    LOOP,
    FUNCT,
    VAR,
    CLASS,
    BREAK,
    CONTINUE,
    INT,
    REAL,
    RETURN,
    ELSE,
    MATCH,
    STRING,

    /* Not keyword */
    IDENTIFIER,

    /* Literals */
    INTEGER,
    FLOATING,
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
