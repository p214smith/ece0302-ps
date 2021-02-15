#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "limited_size_bag.hpp"

// force template expansion for ints
template class LimitedSizeBag<int>;

TEST_CASE("Empty Test", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

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
