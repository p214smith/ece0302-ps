#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"

template class LinkedList<int>;

TEST_CASE( "TODO", "[LinkedList]" ) {
    LinkedList<int> list;
    REQUIRE(list.isEmpty()==true);
  REQUIRE(list.insert(1,2)==true);
  REQUIRE(list.insert(2,4)==true);
  REQUIRE(list.insert(1,1)==true);
  REQUIRE(list.insert(3,1)==true);
  REQUIRE(list.insert(1,1)==true);
  REQUIRE(list.getLength()==5);
  REQUIRE(list.getEntry(1)==1);
   REQUIRE(list.remove(1)==true);
   list.setEntry(1,4);
   REQUIRE(list.getEntry(1)==4);
   list.clear();
   REQUIRE(list.isEmpty()==true);

 
  
}
