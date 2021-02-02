#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "bag.hpp"

// force template expansion
template class Bag<int>;

TEST_CASE("test add ", "[Bag]"){
  Bag<int> b;
  REQUIRE(b.add(2)==true);
  REQUIRE(b.add(3)==true);
  REQUIRE(b.add(4)==true);
  REQUIRE(b.add(4)==true);
  REQUIRE(b.add(5)==true);
  REQUIRE(b.add(6)==true);
  REQUIRE(b.getCurrentSize()==6);
  REQUIRE(b.getFrequencyOf(4)==2);
  REQUIRE(b.remove(2)==true);
  REQUIRE(b.getCurrentSize()==5);
  REQUIRE(b.contains(6)==true);
  REQUIRE(b.isEmpty()==false);
  b.clear();
  REQUIRE(b.isEmpty()==true);

}
