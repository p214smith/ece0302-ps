#include "frontier_queue.hpp"

// TODO implement the member functions here

template <typename T>
State<T> frontier_queue<T>::pop() {
  if (queue.size()==1){
  State<T> popper = queue[0];
  queue.pop_back();
  return popper;
  }
  else
  {
  State<T> popValue = queue[0];
  int i = queue.size() -1;
  queue[0] = queue[i];
  queue.pop_back();
  i = 0;
  int leftChild, rightChild;
  while (i <= queue.size()-1)
  {
     leftChild = (2 * i )+1;
        rightChild = (2 * i) +2;
        if ( i == queue.size()-1)
        break;
        else if (leftChild > queue.size()-1)
        break;
        else if (rightChild > queue.size() -1)
        {
          if (queue[i].getFCost()>queue[leftChild].getFCost())
          {
            State<T> swapper = queue[i];
            queue[i] = queue[leftChild];
            queue[leftChild] = swapper;
            i = leftChild +1;
          }
          else
          i = queue.size();
        }
        else
        {
          if (queue[leftChild].getFCost() > queue[rightChild].getFCost())
          {
            if (queue[i].getFCost() > queue[rightChild].getFCost())
            {
            State<T> swapper = queue[i];
            queue[i] = queue[rightChild];
            queue[rightChild] = swapper;
            i = rightChild;
          }
          else
          i = queue.size();
          }
          else
          {
            if (queue[i].getFCost() > queue[leftChild].getFCost())
            {
            State<T> swapper = queue[i];
            queue[i] = queue[leftChild];
            queue[leftChild] = swapper;
            i = leftChild;
          }
          else
          i = queue.size();
          }
          }
        }
        return popValue;
  }
  }
  

template <typename T>
void frontier_queue<T>::push(const T &p, std::size_t cost, std::size_t heur) {

  State<T> add(p,cost,heur);
  if (queue.empty())
  queue.push_back(add);
  else
  {
    queue.push_back(add);
    int i = queue.size()-1;
    int current = i;
    int parent = (i-1)/2;
    while (i>0)
    {
      if ( queue[current].getFCost() < queue[parent].getFCost())
      {
        State<T> swapper = queue[current];
        queue[current] = queue[parent];
        queue[parent] = swapper;
        i = parent;
        current = i;
        parent = (i-1)/2;
    }
    else 
    i = 0;
    }

    }
  }


template <typename T>
bool frontier_queue<T>::empty() {

  //TODO

  return queue.empty();
}

template <typename T> 
bool frontier_queue<T>::contains(const T &p) {

  for (int i = 0; i < queue.size();i++)
  {
    if ( p == queue[i].getValue())
    return true;
  }

  return false;

}

template <typename T>
void frontier_queue<T>::replaceif(const T &p, std::size_t cost) {
  std::size_t i = 0;
  if (queue.size() > 0)
  {
  for (i = 0; i < queue.size();i++)
  {
      if ( queue[i].getValue() == p)
      break;
  }
  if (i != queue.size())
  if (queue[i].getPathCost() > cost)
  {
      queue[i].updatePathCost(cost);
      int current = i;
      int parent = (i-1)/2;
      while (i>0)
    {
      if ( queue[current].getFCost() < queue[parent].getFCost())
      {
        State<T> swapper = queue[current];
        queue[current] = queue[parent];
        queue[parent] = swapper;
        i = parent;
        current = i;
        parent = (i-1)/2;
    }
    else 
    i = 0;
    }

  }
  }
}


