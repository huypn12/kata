#include "heap.h"
#include "impl/binary_heap.h"
#include "impl/fibonacci_heap.h"

namespace org::kata {
class PriorityQueueFactory {
public:
  template <typename Scalar>
  std::shared_ptr<FibonacciHeap<Scalar>> CreateFibonacciHeap();
  template <typename Scalar>
  std::shared_ptr<BinaryHeap<Scalar>> CreateBinaryHeap();
};
} // namespace org::kata