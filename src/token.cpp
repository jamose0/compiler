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
        out << "IF";
        break;
    }
    case TokenType::FOR: {
        out << "FOR";
        break;
    }
    case TokenType::WHILE: {
        out << "WHILE";
        break;
    }
    case TokenType::LOOP: {
        out << "LOOP";
        break;
    }
    case TokenType::FUNCT: {
        out << "FUNCT";
        break;
    }
    case TokenType::VAR: {
        out << "VAR";
        break;
    }
    case TokenType::CLASS: {
        out << "CLASS";
        break;
    }
    case TokenType::BREAK: {
        out << "BREAK";
        break;
    }
    case TokenType::CONTINUE: {
        out << "CONTINUE";
        break;
    }
    case TokenType::INT: {
        out << "INT";
        break;
    }
    case TokenType::REAL: {
        out << "REAL";
        break;
    }
    case TokenType::RETURN: {
        out << "RETURN";
        break;
    }
    case TokenType::ELSE: {
        out << "ELSE";
        break;
    }
    case TokenType::MATCH: {
        out << "MATCH";
        break;
    }
    case TokenType::STRING: {
        out << "STRING";
        break;
    }
    case TokenType::IDENTIFIER: {
        out << "IDENTIFIER";
        break;
    }
    case TokenType::INTEGER: {
        out << "INTEGER";
        break;
    }
    case TokenType::FLOATING: {
        out << "FLOATING";
        break;
    }
    default: {
        out << "No match";
        break;
    }
    }

    out << " Lexeme: |" << t.m_lexeme << '|';

    return out;
}
