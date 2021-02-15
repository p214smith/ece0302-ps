#include "limited_size_bag.hpp"

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag() {
  size = 0;
  m_Bag = new T[MAXSIZE];
}
  

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag(const LimitedSizeBag& x){
  size = x.size;
  for (std::size_t i = 0;i<size;i++)
  m_Bag[i] = x.m_Bag[i];
}
    
template<typename T>
LimitedSizeBag<T>::~LimitedSizeBag(){
  delete [] m_Bag;
}
  
template<typename T>
LimitedSizeBag<T>& LimitedSizeBag<T>::operator=(LimitedSizeBag<T>& x)
{  
  if (this != &x)
  {
    this->clear();
    size = x.size;
    for (std::size_t i = 0; i< size; i++)
    this->m_Bag[i] = x.m_Bag[i];
  }
  return *this;
}

template<typename T>
bool LimitedSizeBag<T>::add(const T& item)
{
    if ( size == MAXSIZE )
   return false;
  else
  {
    m_Bag[size] = item;
    size++;
    return true;
  }
}

template<typename T>
bool LimitedSizeBag<T>::remove(const T& item)
{
  if(size == 0) return false;

  std::size_t idx = 0;
  for(std::size_t i = 0; i < size; ++i){
    if(m_Bag[i] == item) break;
    ++idx;
  }

  if(idx == size) return false;

  --size;
  for(std::size_t i = idx; i < size; ++i){
    m_Bag[i] = m_Bag[i+1];
  }

  return true;
}

template<typename T>
bool LimitedSizeBag<T>::isEmpty() const
{
  return (size == 0);
}

template<typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const
{
  return size;
}

template<typename T>
bool LimitedSizeBag<T>::contains(const T& item) const
{  
  return (getFrequencyOf(item) != 0);
}

template<typename T>
void LimitedSizeBag<T>::clear(){size = 0;}

template<typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T & item) const
{
  std::size_t freq = 0;

  for(std::size_t i = 0; i < size; ++i){
    if(m_Bag[i] == item) ++freq;
  }
  
  return freq;
};
