#include "sorted_linked_list.hpp"
#include <stdexcept>

template <typename T>
SortedLinkedList<T>::SortedLinkedList(): LinkedList<T>()
{
}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList<T> & x):
  LinkedList<T>(x)
{
}

template <typename T>
SortedLinkedList<T>& SortedLinkedList<T>::operator=(const SortedLinkedList<T>& x)
{
  LinkedList<T>::operator=(x);
  return *this;
}

template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
  // base destructor gets called automatically
}

template <typename T>
bool SortedLinkedList<T>::isEmpty()
{
  return LinkedList<T>::isEmpty();
}

template <typename T>
std::size_t SortedLinkedList<T>::getLength()
{
  return LinkedList<T>::getLength();
}

template <typename T>
void SortedLinkedList<T>::insert(const T& item)
{
  std::size_t i = 0;
  bool tester = false;
  if (LinkedList<T>::getLength() == 0)
  LinkedList<T>::insert(0,item);
  else
  {
   for (i =0; i <LinkedList<T>::getLength();i++)
    {
      if (item <= LinkedList<T>::getEntry(i)){
      LinkedList<T>::insert(i,item);
      break;
      }
      else if (i = LinkedList<T>::getLength())
      LinkedList<T>::insert(i,item);
    }
   

    
  }
}

template <typename T>
void SortedLinkedList<T>::remove(const T& item)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  
  for (std::size_t i = 0; i< LinkedList<T>::getLength();i++)
    {
      if (item == LinkedList<T>::getEntry(i)){
      LinkedList<T>::remove(i);
      break;
      }
    }
}

template <typename T>
void SortedLinkedList<T>::removeAt(std::size_t position)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  if(position>=LinkedList<T>::getLength()) throw std::range_error("position is to high");
  if(position<0) throw std::range_error("position must be positive");
  LinkedList<T>::remove(position);
}

template <typename T>
void SortedLinkedList<T>::clear()
{
  LinkedList<T>::clear();
}

template <typename T>
T SortedLinkedList<T>::getEntry(std::size_t position)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  if(position>=LinkedList<T>::getLength()) throw std::range_error("position is to high");
  if(position<0) throw std::range_error("position must be positive");
  return LinkedList<T>::getEntry(position);
}

template <typename T>
long int SortedLinkedList<T>::getPosition(const T& newValue)
{
  for (long int i = 0; i < LinkedList<T>::getLength();i++){
    if (newValue >= LinkedList<T>::getEntry(i))
    return i;
  }
  return 0;
}
