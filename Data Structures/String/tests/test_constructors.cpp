#include "catch.hpp"

#include "../codes/String.h"


TEST_CASE("Default Constructor is Checked", "[Constructor]")
{
        String s;
        REQUIRE(s.len() == 0);
        REQUIRE(s[0] == '\0');
}

TEST_CASE("Second Constructor is Checked", "[Constructor]")
{
        String s(11);
        REQUIRE(s.len() == 11);
        REQUIRE(s[-1] == ' ');
        REQUIRE(s[0] == ' ');
        REQUIRE(s[11] == '\0');
}

TEST_CASE("Third Constructor is Checked", "[Constructor]")
{
        const char * str = "Hello World!";
        String s("Hello World!");
        String *s1 = new String(str);

        REQUIRE(s.len() == 12);
        REQUIRE(s[0] == 'H');
        REQUIRE(s[-1] == '!');

        REQUIRE(s == String(str));
        REQUIRE(s == *s1);
}

TEST_CASE("Fourth/Copy Constructor is Checked", "[Constructor]")
{
        String s1("Hello");
        String s2(s1);

        REQUIRE(s2 == s1);

        String s3 = s1;
        REQUIRE(s3 == s1);
}