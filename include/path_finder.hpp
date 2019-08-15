#ifndef __PATH_FINDER__
#define __PATH_FINDER__

#include "adj_list.hpp"

#include <unordered_map>
#include <vector>

namespace org::kata {
class path_finder {
 public:
  static std::vector<int> dijsktra(adj_list G, int src, int dst);
  static std::unordered_map<int, int> sssp(adj_list G, int src);
};

}  // namespace org::kata

#endif