#include "sorted_linked_list.hpp"
#include <stdexcept>

template <typename T>
SortedLinkedList<T>::SortedLinkedList(): LinkedList<T>()
{

}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(LinkedList<T> unsorted_list) 
{
  list.insert(0,unsorted_list.getEntry(0));
  for(size_t i=1;i<unsorted_list.getLength(); i++){
    if(unsorted_list.getEntry(i)>list.getEntry(i)){
      list.insert(i,unsorted_list.getEntry(i));
    }
    else{
      list.insert(i-1,unsorted_list.getEntry(i));
    }
  }
}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList<T> & x):
  LinkedList<T>(x)
{
  for(size_t i=0;i<x.getLength();i++){
    list.insert(i,x.getEntry(i));
  }
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
bool SortedLinkedList<T>::isEmpty() const noexcept
{
  return LinkedList<T>::isEmpty();
}

template <typename T>
std::size_t SortedLinkedList<T>::getLength() const noexcept
{
  return LinkedList<T>::getLength();
}

template <typename T>
void SortedLinkedList<T>::insert(const T& item)
{
  int position=0;
  while(item>list.getEntry(position)){
    position++;
  }
  list.insert(position,item);
}

template <typename T>
void SortedLinkedList<T>::remove(const T& item) throw()
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  
  int position=0;
  while(item != list.getEntry(position)){
    position++;
  }
  list.remove(position);
}

template <typename T>
void SortedLinkedList<T>::removeAt(std::size_t position) throw()
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  
  list.remove(position);
}

template <typename T>
void SortedLinkedList<T>::clear()
{
  LinkedList<T>::clear();
}

template <typename T>
T SortedLinkedList<T>::getEntry(std::size_t position) const throw()
{
  return LinkedList<T>::getEntry(position+1);
}

template <typename T>
long int SortedLinkedList<T>::getPosition(const T& item)
{
  // todo
  return 0;
}
