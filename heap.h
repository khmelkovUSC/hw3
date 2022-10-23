#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator()) : m_(m), c_(c) {};

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data_;
  // Aryness:
  size_t m_;
  // Comparator:
  PComparator c_;
  // Returns true if the given index has a node
  bool nodeExists(size_t index);
  // Swaps the node at the given index with its best child, if it has one
  // and continues until there are no better children to swap with
  void trickleDown(size_t index);
  // Swaps the node at the given index with its parent, if its parent is better than it
  // and continues until there is no better parent to swap with
  void trickleUp(size_t index);
};

// Add implementation of member functions here

template <typename T, typename PComparator>
bool Heap<T,PComparator>::nodeExists(size_t index) {
  if (index<data_.size() && index >= 0) return true;
  else return false;
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleDown(size_t index) {
  size_t firstChild = index*m_ + 1;
  // Stop if there are no children to even swap with
  if (!nodeExists(firstChild)) return;

  size_t bestChild = firstChild;
  for (size_t i = 2; i<m_; i++) {
    size_t currChild = index*m_ + i;
    // If the child exists and is better than the current best child, update the bestChild index
    if (nodeExists(currChild)) {
      if (c_(data_[currChild], data_[bestChild])) bestChild = currChild;
    }
  }

  // If the bestchild is better than the inputted node, swap them
  if (c_(data_[bestChild], data_[index])) {
    std::swap(data_[bestChild], data_[index]);
    // Continue trickling down recursively
    trickleDown(bestChild);
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(size_t index) {
  size_t parent = index/m_ - 1;
  // Stop if there is no parent
  if (!nodeExists(parent)) return;

  // If the given node is better than its parent, swap them
  if (c_(data_[index], data_[parent])) {
    std::swap(data_[index], data_[parent]);
    // Continue trickling up recursively
    trickleUp(parent);
  }
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data_.front();


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
  throw std::underflow_error("Heap is empty");
  }
  // Get rid of the top element and move the last element up to the top/root
  std::swap(data_.front(), data_.back());
  data_.pop_back();

  // Trickle the new root value down to its proper place
  trickleDown(0);
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
  return data_.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
  return data_.size();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
  // Add the item at the end and trickle it up
  data_.push_back(item);
  trickleUp(data_.size()-1);
}


#endif

