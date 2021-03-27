#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "romano.hpp"
#include <vector>

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

TEST_CASE("TEST should ignore captalization")
{
    REQUIRE(romano("i") == 1);
    REQUIRE(romano("v") == 5);
    REQUIRE(romano("x") == 10);
    REQUIRE(romano("l") == 50);
    REQUIRE(romano("c") == 100);
    REQUIRE(romano("d") == 500);
    REQUIRE(romano("m") == 1000);
}

TEST_CASE("TEST less than five")
{
    REQUIRE(romano("ii") == 2);
    REQUIRE(romano("iii") == 3);
}