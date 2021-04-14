#include "deque.hpp"
#include <stdexcept>

template <typename T>
Deque<T>::Deque(): LinkedList<T>()
{
}

template <typename T>
Deque<T>::Deque(const Deque<T> & x):
  LinkedList<T>(x)
{
}

template <typename T>
Deque<T>& Deque<T>::operator=(const Deque<T>& x)
{
  LinkedList<T>::operator=(x);
  return *this;
}

template <typename T>
Deque<T>::~Deque()
{
  // base destructor gets called automatically
}

template <typename T>
bool Deque<T>::isEmpty() const noexcept
{
  return LinkedList<T>::isEmpty();
}

template <typename T>
void Deque<T>::pushFront(const T & item)
{
    LinkedList<T>::insert(0,item);
}

template <typename T>
void Deque<T>::popFront()
{
    if(isEmpty()) throw std::range_error("Queue is empty");
    LinkedList<T>::remove(0);
}

template <typename T>
T Deque<T>::front() const
{
     if(isEmpty()) throw std::range_error("Queue is empty");
    return LinkedList<T>::getEntry(0);
}

template <typename T>
void Deque<T>::pushBack(const T & item)
{
    LinkedList<T>::insert(LinkedList<T>::getLength(),item);
}

template <typename T>
void Deque<T>::popBack()
{
    if(isEmpty()) throw std::range_error("Queue is empty");
    LinkedList<T>::remove(LinkedList<T>::getLength()-1);
}

template <typename T>
T Deque<T>::back() const
{
    if(isEmpty()) throw std::range_error("Queue is empty");
    return LinkedList<T>::getEntry(LinkedList<T>::getLength()-1);
}
template <typename T>
bool Deque<T>::findItem(const T & item)
{
  if (LinkedList<T>::isEmpty())
  return false;
  int i = 0;
  while (i < LinkedList<T>::getLength()){
    if (item == LinkedList<T>::getEntry(i))
    return true;
    i++;
  }
  return false;
}
