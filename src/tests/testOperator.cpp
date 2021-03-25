#include "common.h"

#include <iostream>
#include <string>

TEST_CASE("Operator", "[op]")
{
    Scanner s{"+ \n\t -* /\n < > <= \n >="};
    Token t{s.nextToken()};
    REQUIRE(t.getLexeme() == "+");
    REQUIRE(t.getType() == TokenType::PLUS);
    t = s.nextToken();
}
