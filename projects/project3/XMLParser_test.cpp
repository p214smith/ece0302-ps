#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include <iostream>
#include "catch.hpp"
#include "XMLParser.hpp"

using namespace std;

// TODO Implement tests of your Stack class and XMLParser class here

TEST_CASE( "Test Bag add", "[XMLParser]" )
{
	   INFO("Hint: testing Bag add()");
		// Create a Bag to hold ints
		Bag<int> intBag;
		int testSize = 2;
		int bagSize;
		bool success;
		for (int i=0; i<testSize; i++) {
			success = intBag.add(i);
			REQUIRE(success);
			bagSize = intBag.size();
			success = (bagSize == (i+1));
			REQUIRE(success);
		}
}

TEST_CASE( "Test Stack push", "[XMLParser]" )
{
	   INFO("Hint: testing Stack push()");
		// Create a Stack to hold ints
		Stack<int> intStack;
		int testSize = 3;
		int stackSize;
		bool success;
		for (int i=0; i<testSize; i++) {
			success = intStack.push(i);
			REQUIRE(success);
			stackSize = intStack.size();
			success = (stackSize == (i+1));
			REQUIRE(success);
		}
}

TEST_CASE( "Test XMLParser tokenizeInputString", "[XMLParser]" )
{
	   INFO("Hint: tokenize single element test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = " <heading>content</heading>";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		vector<TokenStruct> tokenizedInput = myXMLParser.returnTokenizedInput();
		REQUIRE(success);
		REQUIRE(tokenizedInput[0].tokenString == "heading");
		REQUIRE(tokenizedInput[0].tokenType == START_TAG);
		REQUIRE(tokenizedInput[1].tokenString == "content");
		REQUIRE(tokenizedInput[1].tokenType == CONTENT);
		REQUIRE(tokenizedInput[2].tokenString == "heading");
		REQUIRE(tokenizedInput[2].tokenType == END_TAG);
		
		success = myXMLParser.parseTokenizedInput();
		REQUIRE(success);
}

