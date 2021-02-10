#include "bitset.hpp"

#include <iostream>
#include <iomanip>

Bitset::Bitset(){
    m_bits = 8;
    m_bitSet = new int[m_bits];
    for (u_int i = 0 ;i< m_bits;i++)
    *(m_bitSet + i) = 0;
}

Bitset::Bitset(intmax_t size){
    m_bits = size;
    m_bitSet = new int[m_bits];
    for (std::size_t i = 0 ;i< m_bits;i++)
    *(m_bitSet + i) = 0;
}

Bitset::Bitset(const std::string & value){
    m_bits = value.length();
    for (std::size_t i = 0; i< m_bits; i++){
    if (value.at(i)=='1'){
     *(m_bitSet + i)= 1;
    }
    else 
    {
        *(m_bitSet + i) = 0;
    }
    }
}

Bitset::~Bitset(){
    delete m_bitSet;
}

intmax_t Bitset::size() const{
    return m_bits;
}

bool Bitset::good() const{
    std::size_t i = 0;
    while (i < m_bits){
    if ( *(m_bitSet + i) != 0 && *(m_bitSet + i) != 1)
    {
        break;
        return false;

    }
    i++;
    }
    return true;
    
}
void Bitset::set(intmax_t index){
    *(m_bitSet + index) = 1;
}

void Bitset::reset(intmax_t index){
    *(m_bitSet + index) = 0;
}

void Bitset::toggle(intmax_t index){
    if ( *(m_bitSet + index) == 1)
    {
        *(m_bitSet + index) = 0;
    }
    else 
    {
        *(m_bitSet + index) = 1;
    }
}

bool Bitset::test(intmax_t index){
    if (*(m_bitSet + index) ==1){
        m_test = true;
    }
    else 
    {
        m_test = false;
    }
    return m_test;
}

std::string Bitset::asString() const{
    std::string bitString;
    char a = '1';
    char b = '0';
    for (int i = 0; i < m_bits;i++)
    {
        if ( *(m_bitSet + i) ==1 )
        {
            bitString += a;
        }
        else
        {
            bitString += b;
        }
    }
    return bitString;
}

// TODO
