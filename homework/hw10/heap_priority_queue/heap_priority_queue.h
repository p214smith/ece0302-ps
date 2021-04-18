
#ifndef _HEAP_PRIORITY_QUEUE_H_
#define _HEAP_PRIORITY_QUEUE_H_

#include "abstract_priority_queue.h"
#include "dynamic_array_list.h"

template <typename T>
class HeapPriorityQueue: public AbstractPriorityQueue<T>
{
public:
    
    // return true if the priority queue is empty
    bool isEmpty();
    
    // insert item into the queue
    void add(const T& item);
    
    // remove highest priority item from the queue
    void remove();
    
    // get the item with the highest priority from the queue
    T peek();
    
private:
    
    DynamicArrayList<T> lst;
};

template <typename T>
bool HeapPriorityQueue<T>::isEmpty()
{
    //todo
    return lst.isEmpty();
}

template <typename T>
void HeapPriorityQueue<T>::add(const T& item)
{
    if (lst.isEmpty())
        lst.insert(0,item);
    else
    {
    int i = lst.getLength();
    lst.insert(i,item);
    int parent =(i-1)/2;
    int current = i;
    while (i>0)
    {
    if (lst.getEntry(parent)<lst.getEntry(current))
    {   
        T swapper = lst.getEntry(parent);
        lst.setEntry(parent, lst.getEntry(current));
        lst.setEntry(current,swapper);
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
void HeapPriorityQueue<T>::remove()
{
    if (lst.getLength()==1)
    lst.remove(0);
    else 
    {
    int i = lst.getLength()-1;
    lst.setEntry(0,lst.getEntry(i)); 
    lst.remove(i);
    i = 0;
    int leftChild, rightChild;
    while (i <= lst.getLength()-1)
    {
        leftChild = (2 * i )+1;
        rightChild = (2 * i) +2;
        if ( i == lst.getLength()-1)
        break;
        else if (leftChild > lst.getLength()-1)
        break;
        else if (rightChild > lst.getLength() -1)
    {
        if (lst.getEntry(i)<lst.getEntry(leftChild))
        {
            T swapper = lst.getEntry(i);
            lst.setEntry(i,lst.getEntry(leftChild));
            lst.setEntry(leftChild,swapper);
            i = leftChild+1;
        }
        else 
        i = lst.getLength(); 
    }
    else
        if (lst.getEntry(leftChild)<lst.getEntry(rightChild))
        {
            if (lst.getEntry(i)<lst.getEntry(rightChild))
            {
                T swapper = lst.getEntry(i);
                lst.setEntry(i,lst.getEntry(rightChild));
                lst.setEntry(rightChild,swapper);
                i = rightChild;
            }
            else 
            i = lst.getLength();
        }
        else 
        {
            if (lst.getEntry(i)<lst.getEntry(leftChild))
            {
                T swapper = lst.getEntry(i);
                lst.setEntry(i,lst.getEntry(leftChild));
                lst.setEntry(leftChild,swapper);
                i = leftChild;
            }
            else 
            i = lst.getLength(); 
        }
    }
    }
    
}

template <typename T>
T HeapPriorityQueue<T>::peek()
{
    //todo
    return lst.getEntry(0);
}


#endif // _HEAP_PRIORITY_QUEUE_H_
