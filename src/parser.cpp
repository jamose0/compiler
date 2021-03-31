#include "parser.h"

bool Parser::accept(TokenType tType) const
{
    return tType == m_token.getType();
}

void Parser::parse()
{
    std::cout << "Parsing!\n";
}
