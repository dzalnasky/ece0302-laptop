#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList()
{
  head = nullptr;
  size=0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  clear();
  //delete [] head;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
  size=x.getLength();
  Node<T>* temp = head;
  for(size_t i=0;i<size;i++){
    Node<T>* newNode = new Node<T>();
    newNode->setItem(x.getEntry(i));
    newNode->setNext(nullptr);
    temp->setNext(newNode);
  }
  head = temp;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& x)
{
  size=x.getLength();
  Node<T>* temp = head;
  for(size_t i=0;i<size;i++){
    Node<T>* newNode = new Node<T>();
    newNode->setItem(x.getEntry(i));
    newNode->setNext(nullptr);
    temp->setNext(newNode);
  }
  head = temp;
  return *this;
}

template <typename T>
bool LinkedList<T>::isEmpty() const noexcept
{
  return size==0;
}

template <typename T>
std::size_t LinkedList<T>::getLength() const noexcept
{
  return size;
}

template <typename T>
void LinkedList<T>::insert(std::size_t position, const T& item) throw()
{
  if(position > size || position < 0){
    throw std::range_error("Invalid position");
  }
  //insert at beginning
  if(position==0){
    Node<T>* newNode = new Node<T>();
    newNode->setItem(item);
    newNode->setNext(head);
    head = newNode;
    size++;
    //return true;
  }
  //insert at end
  if(position==size){
    Node<T>* newNode = new Node<T>();
    newNode->setItem(item);
    newNode->setNext(nullptr);
    Node<T>* temp = head;
    while(temp->getNext() != nullptr){
      temp=temp->getNext();
    }
    temp->setNext(newNode);
    size++;
    //return true;
  }
  //insert in middle
  Node<T>* newNode = new Node<T>();
  newNode->setItem(item);
  newNode->setNext(nullptr);
  Node<T>* temp = head;
  while(--position){
    temp=temp->getNext();
  }
  newNode->setNext(temp->getNext());
  temp->setNext(newNode);
  size++;
  //return true;
}

template <typename T>
void LinkedList<T>::remove(std::size_t position) throw()
{
  if(position > size || position < 0 || size ==0){
    throw std::range_error("invalid position");
  }
  //remove from beginning
  if(position==0){
    Node<T>* temp = head;
    head = head->getNext();
    delete [] temp;
    size--;
    //return true;
  }
  //remove from end
  if(position==size-1){
    Node<T>* temp = head;
    while(temp->getNext()->getNext() != nullptr){
      temp = temp->getNext();
    }
    Node<T>* lastNode = temp->getNext();
    temp->setNext(nullptr);
    delete [] lastNode;
    size--;
    //return true;
  }
  //remove from middle
  Node<T>* temp = head;
  for(size_t i=0;i<position-1;i++){
    temp = temp->getNext();
  }
  Node<T>* nextNode = temp->getNext()->getNext();
  delete temp->getNext();
  temp->setNext(nextNode);
  size--; 
  //return true;
}

template <typename T>
void LinkedList<T>::clear()
{
  Node<T>* temp = head;
  Node<T>* next;
  while(temp!=nullptr){
    next = temp->getNext();
    delete temp;
    temp = next;
  }
  delete [] head;
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const throw()
{
  if(position > size || position < 0 || size==0){
    throw std::range_error("invalid position");
  }
  Node<T>* temp = head;
  for(size_t i=0;i<position;i++){
    temp=temp->getNext();
  }
  return temp->getItem();
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue) throw()
{
  if(position > size || position < 0 || size==0){
    throw std::range_error("invalid position");
  }
  Node<T>* temp = head;
  for(size_t i=0;i<position;i++){
    temp=temp->getNext();
  }
  temp->setItem(newValue);
}