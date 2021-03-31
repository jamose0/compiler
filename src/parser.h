#ifndef PARSER_H
#define PARSER_H

#include "token.h"
#include "scanner.h"

#include <string>

class Parser final
{
private:
    /* m_scanner is the parser's scanner. m_token is the current token */
    Scanner m_scanner;
    Token m_token;

    /* This function determines whether or not the current token is of 
       type tType */
    bool accept(TokenType tType) const;

    /* This function calls accept and passes tType as an argument. If accept
       returns false, it will throw a ParseError */
    void expect(TokenType tType) const;
    
public:
    Parser(std::string_view program)
        : m_scanner{program}, m_token{m_scanner.nextToken()}
    {
    }

    void parse();
};

#endif
