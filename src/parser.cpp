#include "parser.h"
#include "parseerror.h"

#include <cstdlib>

void Parser::advanceToken()
{
    m_token = m_s.nextToken();
}

bool Parser::accept(const Token& token)
{
    std::cout << "comparing " << token << " with " << m_token << " <-m\n";
    return token.getType() == m_token.getType();
}

void Parser::expect(const Token& token)
{
    if (accept(token)) {
        return;
    }
    throw ParseError{"fail", 0};
}

void Parser::expectComparison()
{
    std::cout << m_token << "<- expecting\n";
    if (!(accept(Token{TokenType::EQ_EQ, "=="}) ||
          accept(Token{TokenType::BANG_EQ, "!="}) ||
          accept(Token{TokenType::GREATER, ">"}) ||
          accept(Token{TokenType::LESS, "<"}) ||
          accept(Token{TokenType::LESS_EQ, "<="}) ||
          accept(Token{TokenType::GREATER_EQ, ">="})))
    {
        throw ParseError{"uh-oh", 0};
    }       
}

bool Parser::accept_stmt()
{
    return (accept(Token{TokenType::VAR, "var"}) ||
            accept(Token{TokenType::IF, "if"}) ||
            accept(Token{TokenType::WHILE, "while"}));
}

void Parser::expression()
{
    return;
}

void Parser::condition()
{
    std::cout << m_token << '\n';
    if (accept(Token{TokenType::BANG, "!"})) {
        advanceToken();

        std::cout << "recursively calling condition\n";

        condition();
    } else {
        expression();

        std::cout << m_token << '\n';

        expectComparison();

        advanceToken();

        expression();
    }
    //return;
}

void Parser::statement()
{
    if (accept(Token{TokenType::VAR, "var"})) {
        std::cout << "p -> var\n";
        advanceToken();
        /* Identifier name doesn't matter */
        expect(Token{TokenType::IDENTIFIER, ""});
        advanceToken();
        expect(Token{TokenType::EQ, "="});
        advanceToken();
        std::cout << "expanding to expression!\n";
        //std::exit(0);
        //expression();
        advanceToken();
        expect(Token{TokenType::SEMICOLON, ";"});
    } else if (accept(Token{TokenType::IF, "if"})) {
        std::cout << "p -> if\n";
        advanceToken();
        std::cout << "expanding to condition\n";
        condition();
        expect(Token{TokenType::L_BRACE, "{"});
        block();
        expect(Token{TokenType::R_BRACE, "}"});
    }
}

void Parser::block()
{
    std::cout << "calling block\n";
    if (m_token.getType() == TokenType::END)
        std::exit(0);
    std::cout << m_token << '\n';
    
    if (accept_stmt()) {
        std::cout << "expanding to Statement!\n";
        statement();
    }

    advanceToken();

    //std::cout << "didn't match\n";

    block();
}

void Parser::parse()
{
    block();
}
