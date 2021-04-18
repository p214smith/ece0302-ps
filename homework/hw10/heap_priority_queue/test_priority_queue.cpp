#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "heap_priority_queue.h"

TEST_CASE("Test Construction", "[construction]") {
  HeapPriorityQueue<int>  pq;
  REQUIRE(pq.isEmpty());
}

TEST_CASE("Test add", "[add]") {
  HeapPriorityQueue<int>  pq;
  pq.add(25);

  REQUIRE(!pq.isEmpty());
  REQUIRE(pq.peek() == 25);

  pq.add(1);
  REQUIRE(pq.peek() == 25);

  pq.add(78);
  REQUIRE(pq.peek() == 78);

  pq.add(36);
  REQUIRE(pq.peek() == 78);

  pq.add(48);
  REQUIRE(pq.peek() == 78);

  pq.add(96);
  REQUIRE(pq.peek() == 96);

  pq.add(94);
  REQUIRE(pq.peek() == 96);

  pq.add(108);
  REQUIRE(pq.peek() == 108);

  pq.add(5);
  REQUIRE(pq.peek() == 108);
}

TEST_CASE("Test remove", "[remove]") {
  HeapPriorityQueue<int>  pq;
  pq.add(25);
  pq.add(1);
  pq.add(78);
  pq.add(101);
  pq.add(24);
  pq.add(27);
  pq.add(2);
  pq.add(100);
  pq.add(108);
  pq.add(115);
  pq.add(10);

  pq.remove();
  REQUIRE(pq.peek() == 108);
  pq.remove();
  REQUIRE(pq.peek() == 101);
  pq.remove();
  REQUIRE(pq.peek() == 100);
  pq.remove();
  REQUIRE(pq.peek() == 78);
  pq.remove();
  REQUIRE(pq.peek() == 27);
  pq.remove();
  REQUIRE(pq.peek() == 25);
  pq.remove();
  REQUIRE(pq.peek() == 24);
  pq.remove();
  REQUIRE(pq.peek() == 10);
  pq.remove();
  REQUIRE(pq.peek() == 2);
  pq.remove();
  REQUIRE(pq.peek() == 1);
  pq.remove();
  REQUIRE(pq.isEmpty());
}
