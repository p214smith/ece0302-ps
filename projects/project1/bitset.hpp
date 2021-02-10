#ifndef BITSET_HPP
#define BITSET_HPP

#include <string>

class Bitset{
public:

  // DEFAULT CONSTRUCTOR
  Bitset();

  // CONSTRUCTOR THAT SETS SIZE OF BITSET
  Bitset(intmax_t size);

  // CONSTRUCTOR THAT CREATES BITSET OF VALUES FROM STRING 
  Bitset(const std::string & value);

  // DESTRUCTOR
  ~Bitset();

  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

  // GETS SIZE OF BITSET
  intmax_t size() const;

  // CHECKS VALIDITY OF BITSET
  bool good() const;

  // SETS BIT AT INDEX TO TRUE
  void set(intmax_t index);

  // SETS BIT AT INDEX TO FALSE
  void reset(intmax_t index);

  // TOGGLES BIT TO TRUE IF FALSE AND FALSE IF TRUE 
  void toggle(intmax_t index);

  // CHECKS if a SPECIFIC BIT is set
  bool test(intmax_t index);

  // RETURNS BITSET AS A STRING
  std::string asString() const;

private:
  
  //BITSET MEMBER VARIABLE
  int * m_bitSet;
  int m_bits;
  bool m_test;
};

#endif
