#include "dynamic_array_list.h"

#include <algorithm>
#include <stdexcept>

#include <iostream>

template <typename T>
DynamicArrayList<T>::DynamicArrayList()
{

  capacity=100;
  data = new T[capacity];
  size = 0;
  for (std::size_t i =0; i< capacity;i++)
  data[i]=0;
}
  
template <typename T>
DynamicArrayList<T>::DynamicArrayList(const DynamicArrayList<T>& x)
{
  capacity = 100; 
    data = new T[capacity];

  for (std::size_t i = 0;i< capacity;i++)
  {
    data[i] = x.data[i];
  }
  size = x.size;
}
    
template <typename T>
DynamicArrayList<T>::~DynamicArrayList()
{
  std::clog << "DynamicArrayList Destructor called." << std::endl;
  delete [] data;
}

template <typename T>
DynamicArrayList<T>& DynamicArrayList<T>::operator=(DynamicArrayList<T> x)
{
  delete[] data;
  data = nullptr;
  data = new T[capacity];
  for (int i = 0;i<capacity;i++)
  {
    data[i] = x.data[i];
  }
  size = x.size;
  return *this;
}

template <typename T>
void DynamicArrayList<T>::swap(DynamicArrayList<T>& y)
{
  T * holder = new T[y.capacity];
  for (std::size_t i = 0; i< y.capacity;i++)
  {
    holder.data[i]= this->data[i];
    this->data[i] = y.data[i];
    this->data[i] = holder.data[i];
  }
  delete [] holder;
  holder = nullptr;
}

template <typename T>
bool DynamicArrayList<T>::isEmpty()
{
  if (size == 0)
  return true;
  else
  return false;;
}

template <typename T>
std::size_t DynamicArrayList<T>::getLength()
{

  return size;
}

template <typename T>
void DynamicArrayList<T>::insert(std::size_t position, const T& item)
{

    if (size == 0){
    data[0]=item;
    size++;
    }
    else 
  {
    for (std::size_t i=size-1;i>= position;i--)
    {
      data[i] = data[i-1];
    }
    data[position]=item;
    size++;

  }
}

template <typename T>
void DynamicArrayList<T>::remove(std::size_t position)
{
   for (std::size_t i = position; i<size;i++)
    data[i]=data[i+1];
    data[size -1] = 0;
    size--;
}

template <typename T>
void DynamicArrayList<T>::clear()
{
  delete [] data;
  data = new T[capacity];
  size = 0;
}

template <typename T>
T DynamicArrayList<T>::getEntry(std::size_t position)
{
  return data[position];
}

template <typename T>
void DynamicArrayList<T>::setEntry(std::size_t position, const T& newValue)
{
  data[position] = newValue;
}
