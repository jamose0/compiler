#include "parser.h"

bool Parser::accept(const Token& token)
{
    return token.getType() == m_token.getType();
}

void Parser::block()
{
    std::cout << "calling block\n";
    if (m_token.getType() == TokenType::END)
        return;
    
    if (accept(Token{TokenType::VAR, "var"}) ||
        accept(Token{TokenType::IF, "if"}) ||
        accept(Token{TokenType::WHILE, "while"}))
    {
        std::cout << "expanding to Statement!\n";
    }

    block();
}

void Parser::parse()
{
    block();
}
