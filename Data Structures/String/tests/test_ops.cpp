#include "catch.hpp"

#include "../codes/String.h"


TEST_CASE("Comparision Operators are Checked", "[Operator][Comparision]")
{
        String s1 = "Hello";
        String s2 = "     ";
        String *s3 = new String("Hello");
        String blanks(5);
        String s4,s5;

        SECTION("Equality Operator") {
                REQUIRE(s1 == s1);
                REQUIRE(s1 == *s3);
                REQUIRE(s2 == blanks);
                REQUIRE(s4 == s5);
                REQUIRE_FALSE(s1 == s5);
        }

        SECTION("Unequality Operator") {
                REQUIRE_FALSE(s1 != s1);
                REQUIRE(s1 != s2);
                REQUIRE(s1 != blanks);
                REQUIRE(*s3 != s4);
                REQUIRE_FALSE(s4 != s5);
        }

        SECTION("Greater than Operator") {
                REQUIRE(s1 > s2);
                REQUIRE(s1 >= s1);
                REQUIRE(*s3 >= s4);
                REQUIRE(blanks > s5);
        }

        SECTION("Less than Operator") {
                REQUIRE(String("B") > String("A"));
                REQUIRE(s1 <= s1);
                REQUIRE(s4 <= s1);
                REQUIRE(blanks < s1);
        }
}

TEST_CASE("Indexing Operator is Checked", "[Operator]")
{
        String s = "Hello World!!";

        REQUIRE(s[0] == 'H');
        REQUIRE(s[-1] == '!');
        REQUIRE(s[-2] == '!');
        
        s[4] = ' ';
        REQUIRE(s[4] == ' ');
        REQUIRE(s == String("Hell  World!!"));
}

TEST_CASE("Assignment Operator is Checked", "[Operator]")
{
        String s1;
        String s2 = "Hi!!";

        REQUIRE(s1 != s2);
        s1 = s2;
        REQUIRE(s1 == s2);
}

TEST_CASE("Concatenation Operator is Checked", "[Operator]")
{
        String s1 = "Hi!!";
        String s2("Bye!!");
        String space(1);
        String s;
        s = s1 + space;
        REQUIRE(s == "Hi!! ");
        s = s + s2;
        REQUIRE(s == "Hi!! Bye!!");
}

// Let us consider len also as an operator since we often
// need the length of a string when we use it.
TEST_CASE("len Operator is Checked", "[length][Operator]")
{
        String cup("Is empty?");
        String fill("> It's time to make some tea.");
        String lazy = "But I'm too lazy to do it.";

        REQUIRE(cup.len() == 9);
        REQUIRE(fill.len() != 0);
        REQUIRE(lazy.len() == 26);
}
