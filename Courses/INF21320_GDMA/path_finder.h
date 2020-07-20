#ifndef __PATH_FINDER__
#define __PATH_FINDER__

#include "adj_list.h"

#include <functional>
#include <unordered_map>
#include <vector>

namespace org::kata {
class PathFinder {
public:
  static std::vector<int> Dijsktra(AdjList G, int src, int dst);
  static std::vector<int> AStar(AdjList G, int src, int dst,
                                std::function<double(int)> h); // heuristic func
  static std::vector<int> ALT(AdjList G, int src, int dst);
  static std::vector<int> Yen(AdjList G, int src, int dst, int k);
};
} // namespace org::kata

#endif
