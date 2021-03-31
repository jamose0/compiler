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

void Parser::parse()
{
    if (accept(TokenType::WHILE)) {
        std::cout << "accept while\n";
    }

    expect(TokenType::IF);
    std::cout << "Parsing!\n";
}
