#include <vector>
#include <memory>

namespace org::kata {
template <typename Scalar> class PriorityQueue {
public:
  virtual void Insert(int e) = 0;
  virtual void DecreaseKey(int e, Scalar k) = 0;
  virtual void ExtractMin() = 0;
};



class PriorityQueueFactory {
public:
  std::shared_ptr<FibonacciHeap> CreateFibonacciHeap();
  std::shared_ptr<BinaryHeap> CreateBinaryHeap();
};

} // namespace org::kata
