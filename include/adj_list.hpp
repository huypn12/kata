#ifndef __ADJ_LIST__
#define __ADJ_LIST__

#include <unordered_map>
#include <vector>

namespace org::kata {
class adj_list {
  using edge_list = std::vector<int>;

 private:
  std::unordered_map<int, edge_list> nodes_;

 public:
  adj_list() : nodes_() {}
  ~adj_list();

  int add_node() {
    auto new_node = std::pair<int, edge_list>(nodes_.size(), edge_list());
    nodes_.insert(new_node);
  }

  int add_edge(int i, int j) {
    if (nodes_.find(i) == nodes_.end() || nodes_.find(j) == nodes_.end()) {
      return -1;
    }
    nodes_.at(i).push_back(j);
  }

  edge_list &outgoing(int i) {
    return nodes_.at(i);
  }

};
}  // namespace org::kata
#endif
