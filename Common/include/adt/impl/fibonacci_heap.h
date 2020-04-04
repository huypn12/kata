#include "adt/heap.h"

namespace org::kata {

template <typename Scalar> class FibonacciHeap : public PriorityQueue<Scalar> {
private:
  std::vector<int> container_;

public:
  FibonacciHeap<Scalar>();
  void Insert(int e) override;
  void DecreaseKey(int e) override;
  void ExtractMin() override;
};

template <typename Scalar> FibonacciHeap::FibonacciHeap<Scalar>() {

}

} // namespace org::kata