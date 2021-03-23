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

        /* Keywords */
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
    case TokenType::PUB: {
        out << "PUB";
        break;
    }
    case TokenType::INTERFACE: {
        out << "INTERFACE";
        break;
    }
    case TokenType::IMPORT: {
        out << "IMPORT";
        break;
    }
        /* Not keywords */
    case TokenType::IDENTIFIER: {
        out << "IDENTIFIER";
        break;
    }
    case TokenType::INTEGER_L: {
        out << "INTEGER_L";
        break;
    }
    case TokenType::FLOATING_L: {
        out << "FLOATING_L";
        break;
    }
    case TokenType::STR_L: {
        out << "STR_L";
        break;
    }
        /* Punctuation */
    case TokenType::R_BRACE: {
        out << "R_BRACE";
        break;
    }
    case TokenType::L_BRACE: {
        out << "L_BRACE";
        break;
    }
    case TokenType::R_SQUARE: {
        out << "R_SQUARE";
        break;
    }
    case TokenType::L_SQUARE: {
        out << "L_SQUARE";
        break;
    }
    case TokenType::R_PAREN: {
        out << "R_PAREN";
        break;
    }
    case TokenType::L_PAREN: {
        out << "L_PAREN";
        break;
    }
    case TokenType::SEMICOLON: {
        out << "SEMICOLON";
        break;
    }
    case TokenType::COLON: {
        out << "COLON";
        break;
    }
    case TokenType::COMMA: {
        out << "COMMA";
        break;
    }
    case TokenType::STAR: {
        out << "STAR";
        break;
    }
    case TokenType::SLASH: {
        out << "SLASH";
        break;
    }
    case TokenType::PLUS: {
        out << "PLUS";
        break;
    }
    case TokenType::MINUS: {
        out << "MINUS";
        break;
    }
    case TokenType::EQ: {
        out << "EQ";
        break;
    }
    case TokenType::BANG: {
        out << "BANG";
        break;
    }
    case TokenType::EQ_EQ: {
        out << "EQ_EQ";
        break;
    }
    case TokenType::BANG_EQ: {
        out << "BANG_EQ";
        break;
    }
    case TokenType::GREATER: {
        out << "GREATER";
        break;
    }
    case TokenType::LESS: {
        out << "LESS";
        break;
    }
    case TokenType::GREATER_EQ: {
        out << "GREATER_EQ";
        break;
    }
    case TokenType::LESS_EQ: {
        out << "LESS_EQ";
        break;
    }
    case TokenType::ERROR: {
        out << "ERROR";
        break;
    }
    case TokenType::DOT: {
        out << "DOT";
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
