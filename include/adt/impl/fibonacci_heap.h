#include "adt/heap.h"

namespace org::kata {

template <typename Scalar> class FibonacciHeap : public PriorityQueue<Scalar> {
private:
  std::vector<int> container_;

public:
  void Insert(int e) override;
  void DecreaseKey(int e) override;
  void ExtractMin() override;
};

} // namespace org::kata