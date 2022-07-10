#ifndef _LINKED_LIST_HPP_
#define _LINKED_LIST_HPP_

#include "abstract_list.hpp"
#include "Node.hpp"
#include <stdexcept>

template <typename T>
class LinkedList: public AbstractList<T>
{
public:
  
  // default constructor
  LinkedList();
  
  // copy constructor
  LinkedList(const LinkedList& x);
    
  // destructor
  ~LinkedList();
  
  // copy assignment
  LinkedList& operator=(const LinkedList& x);

  // determine if a list is empty
  bool isEmpty() const noexcept;

  // return current length of the list
  std::size_t getLength() const noexcept;

  // insert item at position in the list
  void insert(std::size_t position, const T& item) throw();

  // remove item at position in the list
  void remove(std::size_t position) throw();

  // remove all items from the list
  void clear();

  // get a copy of the item at position
  T getEntry(std::size_t position) const throw();

  // set the value of the item at position
  void setEntry(std::size_t position, const T& newValue) throw();

private:

  Node<T>* head;
  size_t size;
  
};

#include "linked_list.tpp"

#endif
