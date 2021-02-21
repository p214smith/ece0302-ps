#include "array_list.hpp"

template <typename T>
ArrayList<T>::ArrayList() {

  std::cout<<"How long would you like the list?\n";
  std::cin>>m_max;
  m_arrayList = new T[m_max];
  m_size = 0;
  for (std::size_t i =0; i< m_max;i++)
  m_arrayList[i]=0;

}

template <typename T>
ArrayList<T>::~ArrayList() {delete [] m_arrayList;}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList & rhs){
  m_arrayList = new T[rhs.m_max];

  for (std::size_t i = 0;i<rhs.getLength();i++)
  {
    m_arrayList[i] = rhs.m_arrayList[i];
  }
}

template <typename T>
ArrayList<T> & ArrayList<T>::operator=(const ArrayList & rhs){
  delete [] m_arrayList;
  m_arrayList = new T[rhs.m_max];
  for (std::size_t i = 0;i<rhs.getLength();i++)
  {
    m_arrayList[i] = rhs.m_arrayList[i];
  }

  return *this;
}

template <typename T>
bool ArrayList<T>::isEmpty() const{
  if (m_size == 0)
  return true;
  else
  return false;
}

template <typename T>
std::size_t ArrayList<T>::getLength() const{
  return m_size;
}

template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item){
  if (position < m_max)
  {
    if (m_size == 0){
    m_arrayList[0]=item;
    m_size++;
    return true;
    }
    else 
  {
    for (std::size_t i=m_size-1;i>= position;i--)
    {
      m_arrayList[i] = m_arrayList[i-1];
    }
    m_arrayList[position]=item;
    m_size++;
    return true;

  }}
  else 
  return false;
}

template <typename T>
bool ArrayList<T>::remove(std::size_t position){
  if (position >= m_size)
  return false;
  else 
  {
    for (std::size_t i = position; i<m_size;i++)
    m_arrayList[i]=m_arrayList[i+1];
    m_arrayList[m_size -1] = 0;
    m_size--;
    return true;
  }
}

template <typename T>
void ArrayList<T>::clear() {
  delete [] m_arrayList;
  m_arrayList = new T[m_max];
  m_size = 0;
}

template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const {
  return m_arrayList[position];
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue) {
    m_arrayList[position]= newValue;
    if (position > m_size-1)
    m_size++;
}
