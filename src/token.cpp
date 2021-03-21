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

std::ostream& operator<<(std::ostream& out, const Token &t)
{
    out << "Type: ";
    switch (t.m_type) {
    case TokenType::IF: {
        out << "if";
        break;
    }
    case TokenType::WHILE: {
        out << "while";
        break;
    }
    case TokenType::IDENTIFIER: {
        out << "ident";
        break;
    }
    case TokenType::INTEGER: {
        out << "int";
        break;
    }
    case TokenType::REAL: {
        out << "real";
        break;
    }
    case TokenType::FUNCT: {
        out << "funct";
        break;
    }
    default: {
        out << "No match";
        break;
    }
    }

    out << " Lexeme: " << t.m_lexeme;

    return out;
}
