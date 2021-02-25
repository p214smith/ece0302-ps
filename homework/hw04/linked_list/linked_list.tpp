#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList()
{

  m_head = nullptr; 
  m_length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  clear();
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
  m_length = x.m_length;
  Node<T> * origChainPtr = x.m_head;
  if (origChainPtr == nullptr)
  m_head = nullptr;
  else
  {
    m_head = new Node<T>();
    m_head->setItem(origChainPtr->getItem());
    Node<T> * newChainPtr = m_head;
    origChainPtr = origChainPtr->getNext();
    while ( origChainPtr !=  nullptr)
    {
      T nextItem = origChainPtr->getItem();
      Node<T>* newNodePtr = new Node<T>(nextItem);
      newChainPtr->setNext(newNodePtr);
      newChainPtr = newChainPtr->getNext();
      origChainPtr = origChainPtr->getNext();
    }
    newChainPtr->setNext(nullptr);
  }
}

template <typename T>
void LinkedList<T>::swap(LinkedList<T>& x, LinkedList<T>& y)
{
  LinkedList<T> tmp;
  tmp.m_head = x.m_head;
  x.m_head = y.m_head;
  y.m_head = tmp.m_head;
  std::size_t temp;
  temp = x.m_length;
  x.m_length = y.m_length;
  y.m_length = temp;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& x)
{
  LinkedList<T> temp(x);
  this->m_head = temp.m_head;
  this->m_length = temp.m_length;
  return *this;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
  if (m_length ==0)
  return true; 
  else 
  return false;
}

template <typename T>
std::size_t LinkedList<T>::getLength() const
{
  //TODO
  return m_length;
}

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  if (position>m_length+1)
  return false;
  else if(position == 1){
    Node<T> * cur = new Node<T>;
    cur->setItem(item);
    cur->setNext(m_head);
    m_head=cur;
  
  m_length++;
  return true;
}
  else{
  Node<T> * cur = new Node<T>();
  cur = m_head;
  for (std::size_t i =1; i<position;i++)
  {
    cur= cur->getNext();
  }
  Node<T>* newNode = new Node<T>(item,cur);
  m_length++;
  return true;

}}
template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  Node<T>* pre = new Node<T>();
   Node<T>* cur = new Node<T>();
   pre = nullptr;
   cur = nullptr;
  
  if (position > m_length+1)
  return false;
 else if (position == 1)
 {
   
   cur = m_head;
   m_head= m_head->getNext();
   delete cur;
   cur = nullptr;
   m_length--;
   return true;
 }
 else
 {
   cur = m_head;
   for (std::size_t i =1; i< position;i++)
   {
     pre = cur;
     cur = cur->getNext();
   }
   cur = cur->getNext();
   pre->setNext(cur);
   delete cur;
   cur = nullptr;
   m_length--;
   return true;
 }
 
}

template <typename T>
void LinkedList<T>::clear()
{
  Node<T>* NodeToDeletePtr = m_head;
  while(m_head != nullptr)
  {
    m_head = m_head->getNext();
    NodeToDeletePtr->setNext(nullptr);
    delete NodeToDeletePtr;
    NodeToDeletePtr = m_head;
  }
  m_length = 0;
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  Node<T>* pre = new Node<T>;
  Node<T>* cur = new Node<T>;
  cur = m_head;
  for ( std::size_t i =1 ; i < position;i++)
  {
    pre = cur;
    cur = cur->getNext();
  }
  return cur->getItem();
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
 
  Node<T>* cur = new Node<T>;
  cur = m_head;
  for ( std::size_t i =1 ; i < position;i++)
  {
    cur = cur->getNext();
  }
   cur->setItem(newValue);
}
