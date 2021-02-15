#include "dynamic_bag.hpp"

template<typename T>
DynamicBag<T>::DynamicBag() {
  m_max = 20;
  m_Bag = new T[m_max];
  size = 0;
}
  

template<typename T>
DynamicBag<T>::DynamicBag(const DynamicBag& x){
  size = x.size;
  m_max = x.m_max;
  for (std::size_t i = 0;i<size;i++)
  m_Bag[i] = x.m_Bag[i];
}
    
template<typename T>
DynamicBag<T>::~DynamicBag(){
  delete [] m_Bag;
}
  
template<typename T>
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T>& x)
{  
  if (this != &x)
  {
    this->clear();
    size = x.size;
    m_max = x.m_max;
    for (std::size_t i = 0; i< size; i++)
    this->m_Bag[i] = x.m_Bag[i];
  }
  return *this;
}

template<typename T>
bool DynamicBag<T>::add(const T& item)
{
  if ( size == m_max)
   return false;
  else
  {
    m_Bag[size] = item;
    size++;
    return true;
  }

}

template<typename T>
bool DynamicBag<T>::remove(const T& item)
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
bool DynamicBag<T>::isEmpty() const
{
  return (size == 0);
}

template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const
{
  return size;
}

template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{  
  return (getFrequencyOf(item) != 0);
}

template<typename T>
void DynamicBag<T>::clear(){size = 0;}

template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{
  std::size_t freq = 0;

  for(std::size_t i = 0; i < size; ++i){
    if(m_Bag[i] == item) ++freq;
  }
  
  return freq;
};
