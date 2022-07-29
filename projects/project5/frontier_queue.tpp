#include "frontier_queue.hpp"

// TODO implement the member functions here

template <typename T>
State<T> frontier_queue<T>::pop() throw(){
  if(queue.size() == 0){
    throw std::out_of_range("Error: nothing to pop");
  }
  //pop root, and replace with last element
  State<T> returnValue = queue[0];
  queue[0] = queue.back();
  queue.pop_back();
  heapdown(0);
  return returnValue;
}

template <typename T>
void frontier_queue<T>::push(const T &p, std::size_t cost, std::size_t heur) {
  State<T> newState(p,cost,heur);
  queue.push_back(newState);
  int index = queue.size()-1;

  while(queue[index].getFCost() < queue[parent(index)].getFCost() && index != 0){
    //swap the values
    State<T> temp = queue[index];
    queue[index] = queue[parent(index)];
    queue[parent(index)] = temp;
    index = parent(index);
  }

}

template <typename T>
bool frontier_queue<T>::empty() {
  return queue.size() == 0;
}

template <typename T> 
bool frontier_queue<T>::contains(const T &p) {
  for(int i=0;i<queue.size();i++){
    if(queue[i].getValue() == p){
      return true;
    }
  }
  return false;

}

template <typename T>
void frontier_queue<T>::replaceif(const T &p, std::size_t cost) {

  //TODO

}

//heap down function, compares with getFCost
template <typename T>
void frontier_queue<T>::heapdown(int index){
  //get children of index
  int leftchild = left(index), rightchild = right(index), smallerChild=index;

  //compare queue[index] with left and right child to find smaller value
  if(leftchild < queue.size() && queue[leftchild].getFCost() < queue[index].getFCost() && queue[leftchild].getFCost() < queue[rightchild].getFCost()){
    smallerChild=leftchild;
  }
  if(rightchild < queue.size() &&  queue[rightchild].getFCost() < queue[index].getFCost() && queue[rightchild].getFCost() < queue[leftchild].getFCost()){
    smallerChild=rightchild;
  }

  //swap smaller value and recursively call heapdown
  if(smallerChild != index){
    //swap values
    State<T> temp = queue[index];
    queue[index] = queue[smallerChild];
    queue[smallerChild] = temp;
    heapdown(smallerChild);
  }

}

//print function
template <typename T>
void frontier_queue<T>::print(){
  for(int i=0;i<queue.size();i++){
    std::cout<<queue[i].getValue()<<" "<< queue[i].getPathCost()<<" "<<queue[i].getFCost()<<std::endl;
  }
}