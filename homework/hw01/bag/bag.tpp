#include "bag.hpp"

// empty implementation                                                                                                     

template <typename T> Bag<T>::Bag() {
    count = 0;
    
}


template <typename T> Bag<T>::~Bag() {}

template <typename T> std::size_t Bag<T>::getCurrentSize() const { return count; }

template <typename T> bool Bag<T>::isEmpty() const { 
    if ( count != 0)
    return false; 
    else 
    return true;}

template <typename T> bool Bag<T>::add(const T& entry) { 
    if (count < 20){
    item[count] = entry;
    count++;
    return true;}
    else{
        std::cout<< "Bag is full!"<< std::endl;
    return false; }}

template <typename T> bool Bag<T>::remove(const T& entry) { 
    bool response = false;
    for (int i = 0;i < 20;i++)
    if ( entry == item[i]){
        for (int k = i;k<20;k++)
            item[k]=item[k+1];
    count--;
    response = true;}


    return response; }

template <typename T> void Bag<T>::clear() {
    count = 0;
    for (int i = 0;i<20;i++)
    item[i]=0;
}

template <typename T> std::size_t Bag<T>::getFrequencyOf(const T& entry) const { 
    size_t frequency = 0;
    for ( int i = 1; i < 20;i++){
        if ( item[i]== entry)
        frequency++;
    }
    return frequency; }

template <typename T> bool Bag<T>::contains(const T& entry) const { 
    bool contain = false;
    for (int i = 0 ;i<20;i++)
    {
        if (item[i] == entry)
            contain = true;
    }
    return contain; }

