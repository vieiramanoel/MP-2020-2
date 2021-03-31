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
    REQUIRE(romano("i") == 1);
    REQUIRE(romano("ii") == 2);
    REQUIRE(romano("iii") == 3);
    REQUIRE(romano("iv") == 4);
}

TEST_CASE("TEST 5 to 9")
{
    REQUIRE(romano("v") == 5);
    REQUIRE(romano("vi") == 6);
    REQUIRE(romano("vii") == 7);
    REQUIRE(romano("viii") == 8);
    REQUIRE(romano("ix") == 9);
}

TEST_CASE("TEST 10 to 20")
{
    REQUIRE(romano("x") == 10);
    REQUIRE(romano("xiii") == 13);
    REQUIRE(romano("xv") == 15);
    REQUIRE(romano("xviii") == 18);
    REQUIRE(romano("xix") == 19);
    REQUIRE(romano("xx") == 20);
}

TEST_CASE("TEST 5's as subtractor")
{
    REQUIRE(romano("vx") == -1);
    REQUIRE(romano("lc") == -1);
    REQUIRE(romano("dm") == -1);
}

TEST_CASE("TEST invalid repetitions")
{
    REQUIRE(romano("iiii") == -1);
    REQUIRE(romano("xiiii") == -1);
    REQUIRE(romano("xxxx") == -1);
    REQUIRE(romano("llll") == -1);
    REQUIRE(romano("vviii") == -1);
    REQUIRE(romano("dddddd") == -1);
}

TEST_CASE("TEST 20 to 100")
{
    REQUIRE(romano("xx") == 20);
    REQUIRE(romano("xxx") == 30);
    REQUIRE(romano("xxxx") == -1);
    REQUIRE(romano("xl") == 40);
    REQUIRE(romano("xlv") == 45);
    REQUIRE(romano("xlix") == 49);
    REQUIRE(romano("l") == 50);
    REQUIRE(romano("lx") == 60);
    REQUIRE(romano("lxx") == 70);
    REQUIRE(romano("lxxx") == 80);
    REQUIRE(romano("lxxxx") == -1);
    REQUIRE(romano("xc") == 90);
    REQUIRE(romano("c") == 100);
}

TEST_CASE("TEST 101 to 1000")
{
    REQUIRE(romano("ci") == 101);
    REQUIRE(romano("cc") == 200);
    REQUIRE(romano("ccc") == 300);
    REQUIRE(romano("cccc") == -1);
    REQUIRE(romano("cd") == 400);
    REQUIRE(romano("xd") == -1);
    REQUIRE(romano("d") == 500);
    REQUIRE(romano("dc") == 600);
    REQUIRE(romano("dcc") == 700);
    REQUIRE(romano("dccc") == 800);
    REQUIRE(romano("dm") == -1);
    REQUIRE(romano("cm") == 900);
    REQUIRE(romano("m") == 1000);
}

TEST_CASE("TEST 100 to 300")
{
    REQUIRE(romano("cxii") == 112);
    REQUIRE(romano("cxxviii") == 128);
    REQUIRE(romano("cxxxix") == 139);
    REQUIRE(romano("ccxlix") == 249);
    REQUIRE(romano("ccxcix") == 299);
    REQUIRE(romano("ccc") == 300);
}

TEST_CASE("TEST 301 to 500")
{
    REQUIRE(romano("cccxxiv") == 324);
    REQUIRE(romano("cccxlix") == 349);
    REQUIRE(romano("ccclxxix") == 379);
    REQUIRE(romano("ccclxxxix") == 389);
    REQUIRE(romano("cdlxxxxix") == -1);
    REQUIRE(romano("cdxiv") == 414);
    REQUIRE(romano("cdxix") == 419);
    REQUIRE(romano("cdlxxix") == 479);
    REQUIRE(romano("cdxcix") == 499);
    REQUIRE(romano("d") == 500);
    REQUIRE(romano("xd") == -1);
}

TEST_CASE("TEST 500 to 1000")
{
    REQUIRE(romano("dxxiv") == 524);
    REQUIRE(romano("dcxlvii") == 647);
    REQUIRE(romano("dclxix") == 669);
    REQUIRE(romano("dcclxxxix") == 789);
    REQUIRE(romano("dcclxxxxix") == -1);
    REQUIRE(romano("dcccxiv") == 814);
    REQUIRE(romano("dccccxix") == -1);
    REQUIRE(romano("cmxxix") == 929);
    REQUIRE(romano("cmxcix") == 999);
    REQUIRE(romano("m") == 1000);
    REQUIRE(romano("xm") == -1);
}

TEST_CASE("TEST 1000 to 3000")
{
    REQUIRE(romano("m") == 1000);
    REQUIRE(romano("mix") == 1009);
    REQUIRE(romano("mdcclxxxix") == 1789);
    REQUIRE(romano("mcmxcix") == 1999);
    REQUIRE(romano("mdccccxix") == -1);
    REQUIRE(romano("mm") == 2000);
    REQUIRE(romano("mmcxxix") == 2129);
    REQUIRE(romano("mmdcxlvii") == 2647);
    REQUIRE(romano("mmdcccxiv") == 2814);
    REQUIRE(romano("mmmm") == -1);
    REQUIRE(romano("mmm") == 3000);
    REQUIRE(romano("m") == 1000);
    REQUIRE(romano("xm") == -1);
}