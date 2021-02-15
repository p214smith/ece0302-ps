#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "dynamic_bag.hpp"

// force template expansion for ints
template class DynamicBag<int>;

TEST_CASE("Calling all public members", "[DynamicBag]"){
  DynamicBag<int> b;

  REQUIRE(b.add(0)==true);
  REQUIRE(b.add(1)==true);
  REQUIRE(b.remove(0)==true);
  REQUIRE(b.isEmpty()==false);
  REQUIRE(b.getCurrentSize()==1);
  
  REQUIRE(b.getFrequencyOf(1)==1);
  REQUIRE(b.contains(1)==true);
  
  b.clear();
  REQUIRE(b.isEmpty()==true);
}
