#include "sorted_list.h"

template <typename T, typename L>
SortedList<T, L>::SortedList()
{
  // nothing to do, plist gets created on the stack
}

template <typename T, typename L>
SortedList<T, L>::SortedList(const SortedList<T, L> & x)
{
  plist = x.plist; // use copy assignment to implement copy construction
}

template <typename T, typename L>
SortedList<T, L>& SortedList<T, L>::operator=(const SortedList<T, L>& x)
{
  plist = x.plist;
  return *this;
}

template <typename T, typename L>
SortedList<T, L>::~SortedList()
{
  // plist destructor gets called automatically
}

template <typename T, typename L>
bool SortedList<T, L>::isEmpty()
{
  return plist.isEmpty();
}

template <typename T, typename L>
std::size_t SortedList<T, L>::getLength()
{
  return plist.getLength();
}

template <typename T, typename L>
void SortedList<T, L>::insert(const T& item)
{
  std::size_t i = 0;
  if (plist.getLength() == 0)
  plist.insert(0,item);
  else
  {
   for (i =0; i <plist.getLength();i++)
    {
      if (item <= plist.getEntry(i)){
      plist.insert(i,item);
      break;
      }
      else if (i = plist.getLength())
      plist.insert(i,item);
    }
   

    
  }
}

template <typename T, typename L>
void SortedList<T, L>::remove(const T& item)
{
  if(plist.isEmpty()) throw std::range_error("empty list in remove");
  
  for (std::size_t i = 0; i< plist.getLength();i++)
    {
      if (item == plist.getEntry(i)){
      plist.remove(i);
      break;
      }
    }
}

template <typename T, typename L>
void SortedList<T, L>::removeAt(std::size_t position)
{
  plist.remove(position);
}

template <typename T, typename L>
void SortedList<T, L>::clear()
{
  plist.clear();
}

template <typename T, typename L>
T SortedList<T, L>::getEntry(std::size_t position)
{
  return plist.getEntry(position);
}

template <typename T, typename L>
long int SortedList<T, L>::getPosition(const T& newValue)
{
  for (long int i = 0; i < plist.getLength();i++){
    if (newValue >= plist.getEntry(i))
    return i;
  }
}
