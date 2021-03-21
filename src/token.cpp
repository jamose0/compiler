#include "token.h"

/* Token member functions  */

TokenType Token::getType()
{
    return m_type;
}

std::string_view Token::getLexeme()
{
    return m_lexeme;
}
