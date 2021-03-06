#ifndef SCANNER_H
#define SCANNER_H

/*
*  Header file for the Scanner class
*
*  By the way, I already know that the scanner design
*  might be fairly stupid...
*/

#include "token.h"

#include <string>
#include <string_view>
#include <iostream>

/* MACRO */
#define MAKE_TOK(type, pointer, len) \
    Token{TokenType::type, std::string{pointer, len}}
/* END */

class Scanner
{
private:
    // source string
    const std::string m_src;

    size_t m_line_num;

    // Pointer to item of string
    char* m_ip;

    void skipWS();
    // Consume and return the next character of the source string
    char nextChar();

    // Return but do not consume the next character of the source string
    char peekChar();

    //bool matchStr(char* p1, std::string_view p2, int len);

    char rollBack();

    bool isEligibleForIdent();

    bool checkKW(std::string_view cmp);

    Token getIdent(char* sp);

    Token getNumber(char* sp);

public:
    Scanner(std::string_view src);

    virtual ~Scanner() {}

    Token nextToken();

    bool isAtEnd();

    size_t getLine() const;
};

#endif
