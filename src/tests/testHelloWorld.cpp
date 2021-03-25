#include "../scanner.h"
#include "../token.h"

#include <catch2/catch.hpp>

#include <iostream>
#include <string>

TEST_CASE("Hello World", "[what]")
{
    Scanner s{"#comment\n funct main() : ();"};
    Token t{s.nextToken()};
    REQUIRE(t.getLexeme() == "funct");
    REQUIRE(t.getType() == TokenType::FUNCT);
}
