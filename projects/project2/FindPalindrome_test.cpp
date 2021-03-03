#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method

TEST_CASE( "Test FindPalindrome add a non-allowable word", "[FindPalindrome]" )
{
	INFO("Hint: add a single non-allowable word");
	FindPalindrome b;
	std::vector<std::string> s,k;
	k.push_back("a");
	s.push_back("a");
	REQUIRE(b.add("kayak") == true);
	REQUIRE(b.cutTest1(s)==true);
	REQUIRE(b.cutTest2(s,k)==true);
	REQUIRE(b.number()==1);
	REQUIRE(b.add("aa")== true);
}

