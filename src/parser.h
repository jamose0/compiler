#ifndef PARSER_H
#define PARSER_H

#include <string>

#include "scanner.h"
#include "token.h"

class Parser final
{
private:
    Scanner m_s;
    Token m_token;

    void advanceToken();

    bool accept(const Token& token);

    void expect(const Token& token);

    void expectComparison();

    bool accept_stmt();

    void factor();

    void termP();

    void term();

    void expressionP();

    void expression();

    void condition();

    void statement();

    void block();

public:
    Parser(std::string_view inp) : m_s{inp}, m_token{m_s.nextToken()}
    {
        //std::cout << token << '\n';
    }

    void parse();
};

#endif
