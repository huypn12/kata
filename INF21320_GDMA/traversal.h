#include "adj_list.h"

#include <vector>

namespace org::kata {
class traversal {
 public:
  static std::vector<int> bfs(AdjList graph, int start_node, int stop_node);
  static std::vector<int> bfs(AdjList graph, int start_node);
  static std::vector<int> dfs(AdjList graph, int start_node);
};
}  // namespace org::kata
