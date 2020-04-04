#ifndef __ADJ_LIST__
#define __ADJ_LIST__

#include <unordered_map>
#include <vector>

namespace org::kata {
class AdjList {
  using EdgeList = std::vector<int>;

 private:
  std::unordered_map<int, EdgeList> nodes_;

 public:
  AdjList() : nodes_() {}
  ~AdjList();

  int AddNode() {
    auto new_node = std::pair<int, EdgeList>(nodes_.size(), EdgeList());
    nodes_.insert(new_node);
    return nodes_.size();
  }

  int AddEdge(int i, int j) {
    if (nodes_.find(i) == nodes_.end() || nodes_.find(j) == nodes_.end()) {
      return -1;
    }
    nodes_.at(i).push_back(j);
    return nodes_.at(i).size();
  }

  EdgeList &outgoing(int i) {
    return nodes_.at(i);
  }

};
}  // namespace org::kata
#endif
