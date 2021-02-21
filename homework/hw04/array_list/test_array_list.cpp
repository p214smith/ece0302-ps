#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "array_list.hpp"

//force class expansion
template class ArrayList<int>;

TEST_CASE( "Test", "[ArrayList]" ) {

  ArrayList<int> list;
  REQUIRE(list.isEmpty()==true);
  REQUIRE(list.insert(0,1)==true);
  REQUIRE(list.insert(1,1)==true);
  REQUIRE(list.insert(2,1)==true);
  REQUIRE(list.insert(2,1)==true);
  REQUIRE(list.insert(4,1)==true);
  REQUIRE(list.getLength()==5);
  REQUIRE(list.getEntry(2)==1);
  REQUIRE(list.remove(2)==true);
  list.setEntry(4,2);
  REQUIRE(list.getLength()==5);
  list.clear();
  REQUIRE(list.getLength()==0);


  
  
  
  
  
  

}
