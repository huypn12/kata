#include <vector>
#include <memory>

namespace org::kata {
template <typename Scalar> class PriorityQueue {
public:
  virtual void Insert(int e) = 0;
  virtual void DecreaseKey(int e, Scalar k) = 0;
  virtual void ExtractMin() = 0;
};

} // namespace org::kata

