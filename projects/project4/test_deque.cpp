#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "deque.hpp"

typedef Deque<int> ListType;

template class Deque<int>;
TEST_CASE("Testing isEmpty", "[Deque]") {
  ListType lst;
  REQUIRE(lst.isEmpty());

  lst.pushFront(1);
  REQUIRE(!lst.isEmpty());

  lst.popFront();
  REQUIRE(lst.isEmpty());
}
TEST_CASE( "Tests", "[deque]" ) {
    ListType lst;
    for(int i = 0; i < 10;i++)
    {
        lst.pushFront(i);
        REQUIRE(lst.front()==i);
    }
    for(int i = 9; i>=0;i--){
    REQUIRE(lst.front()==i);
    lst.popFront();
    }
    REQUIRE(lst.isEmpty());
    for(int i = 0; i < 10;i++)
    {
        lst.pushBack(i);
        REQUIRE(lst.back()==i);
    }
    for(int i = 9; i>=0;i--){
    REQUIRE(lst.back()==i);
    REQUIRE(lst.findItem(i));
    REQUIRE(!lst.findItem(i+10));
    lst.popBack();
    }
    REQUIRE(lst.isEmpty());


}
