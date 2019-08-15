#include "adj_list.hpp"

#include <vector>

namespace org::kata {
class traversal {
 public:
  static std::vector<int> bfs(adj_list graph, int start_node, int stop_node);
  static std::vector<int> bfs(adj_list graph, int start_node);
  static std::vector<int> dfs(adj_list graph, int start_node);
};
}  // namespace org::kata