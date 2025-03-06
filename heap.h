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
  Heap(int m=2, PComparator c = PComparator());

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

  void heapify(size_t index);

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> items_;
  int mary_;
  PComparator comparator_;





};

// Add implementation of member functions here
template<typename T, typename PComparator>
void Heap<T, PComparator>::heapify(size_t index) {
  if( index > 0){
    size_t parent = (index - 1) / mary_;
    if(comparator_(items_[index], items_[parent])){
      std::swap(items_[index], items_[parent]);
      heapify(parent);
    } 
  } else {
      size_t better = index;
      for(int i = 1; i <= mary_; i++) {
        size_t child = mary_ * index + i;
        if((child < items_.size()) and (comparator_(items_[child], items_[better]))) {
          better = child;
        }
      }
      if (better != index) {
        std::swap(items_[index], items_[better]);
        heapify(better);
      }
    }
}

template<typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : mary_(m), comparator_(c) {}

template<typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {
	while(!empty()){
		pop();
	}
}

template<typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
  items_.push_back(item);
  size_t curr = item_.size()-1;

	while(curr > 0)
	{
		size_t parent = (curr -1)/mary_;

		if(comparator_(items_[curr], items_[parent])){
			std::swap(items_[curr], items_[parent]);
			curr = parent;
		}
		else{
			break;
		}
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
    throw std::underflow_error("empty");


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return(items_[0]);



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
    throw std::underflow_error("error");


  }
  std::swap(items_[0], items_[items_.size() -1]);
  items_.pop_back();
  if(!empty()) heapify(0);

}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  return items_.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  return items_.size();
}



#endif

