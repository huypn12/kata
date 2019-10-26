#include "priority_queue.h"

class FibonacciHeap : public PriorityQueue {
private:
  std::vector<int> container_;

public:
  void Insert(int e) override;
  void DecreaseKey(int e) override;
  void ExtractMin() override;
};

void FibonacciHeap::Insert(int e) {}
void FibonacciHeap::DecreaseKey(int e) {}