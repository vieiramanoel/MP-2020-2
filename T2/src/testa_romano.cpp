#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "romano.hpp"

TEST_CASE("Test for 1 digit")
{
    REQUIRE(romano("I") == 1);
    REQUIRE(romano("V") == 5);
    REQUIRE(romano("X") == 10);
    REQUIRE(romano("L") == 50);
    REQUIRE(romano("C") == 100);
    REQUIRE(romano("D") == 500);
    REQUIRE(romano("M") == 1000);
}

TEST_CASE("TEST 1 invalid digit")
{
    REQUIRE(romano("F") == -1);
    REQUIRE(romano("A") == -1);
}