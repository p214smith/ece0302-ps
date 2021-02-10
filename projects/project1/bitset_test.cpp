#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "bitset.hpp"
// THIS IS JUST AN EXAMPLE
// There should be at least one test per Bitset method

TEST_CASE( "Test bitset construction", "[bitset]" ) {

    
    Bitset b(8);  
    REQUIRE(b.size() == 8);
    REQUIRE(b.good()== true);
    b.set(0);
    b.toggle(1);
    b.toggle(2);
    b.reset(2);
    REQUIRE(b.test(1)==true);
    REQUIRE(b.asString()=="11000000");
    
}
