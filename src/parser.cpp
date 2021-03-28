#include "parser.h"
#include "parseerror.h"

#include <cstdlib>

void Parser::advanceToken()
{
    m_token = m_s.nextToken();
}

bool Parser::accept(const Token& token)
{
    return token.getType() == m_token.getType();
}

void Parser::expect(const Token& token)
{
    if (accept(token)) {
        return;
    }
    throw ParseError{"fail", 0};
}

bool Parser::accept_stmt()
{
    return (accept(Token{TokenType::VAR, "var"}) ||
            accept(Token{TokenType::IF, "if"}) ||
            accept(Token{TokenType::WHILE, "while"}));
}

void Parser::condition()
{
    return;
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
