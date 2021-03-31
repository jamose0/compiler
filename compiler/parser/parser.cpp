#include "parser.h"
#include "parseerror.h"

#include <sstream>

bool Parser::accept(TokenType tType) const
{
    return tType == m_token.getType();
}

void Parser::expect(TokenType tType) const
{
    std::cout << "call expect\n";
    if (!accept(tType)) {
        std::ostringstream msg_stream;
        msg_stream << "Unexpected token: '" << m_token.getLexeme()
                   << "' <- line: " << m_scanner.getLine() << '\n';
        throw ParseError{msg_stream.str(), m_scanner.getLine()};
    }
}

void Parser::advanceToken()
{
    m_token = m_scanner.nextToken();
}

void Parser::factor()
{
    std::cout << m_token << " <- symbol at factor\n";
    if (accept(TokenType::MINUS)) {
        advanceToken();
        factor();
    } else if (accept(TokenType::L_PAREN)) {
        advanceToken();
        expr();
        expect(TokenType::R_PAREN);
        advanceToken();
    } else if (accept(TokenType::IDENTIFIER)) {
        std::cout << "ident\n";
        advanceToken();
    } else if (accept(TokenType::INTEGER_L)) {
        std::cout << "integer\n";
        advanceToken();
    } else if (accept(TokenType::END)) {
        std::cout << "end\n";
        return;
    } else {
        throw ParseError{"unexpected symbol\n", 0};
    }
}

void Parser::termP()
{
    std::cout << "call termP\n";
    if (accept(TokenType::STAR)) {
        advanceToken();
        factor();
        termP();
    } else if (accept(TokenType::SLASH)) {
        advanceToken();
        factor();
        termP();
    }
}

void Parser::term()
{
    std::cout << "call term\n";
    factor();
    std::cout << "return from factor\n";
    termP();
    std::cout << "return from termP\n";
}

void Parser::exprP()
{
    /* These two branches look the same now, but they will be different when
       we build the AST */
    std::cout << "call exprP\n";
    if (accept(TokenType::PLUS)) {
        advanceToken();
        term();
        exprP();
    } else if (accept(TokenType::MINUS)) {
        advanceToken();
        term();
        exprP();
    }
    /* exprP can return nothing */
}

void Parser::expr()
{
    std::cout << "call expr\n";
    term();
    std::cout << "return from term\n";
    exprP();
    std::cout << "return from exprP\n";
}

void Parser::parse()
{
    //if (accept(TokenType::WHILE)) {
    //std::cout << "accept while\n";
    //}

    //expect(TokenType::IF);

    expr();
    std::cout << "Parsing!\n";
}
