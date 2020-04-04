#include "path_finder.h"

#include <unordered_map>
#include <map>

using namespace org::kata;

std::vector<int> PathFinder::Dijsktra(AdjList G, int src, int dst) {
  std::vector<int> dist;
  std::vector<int> prev;
  distance.insert(src, 0);
  
}

std::vector<int> PathFinder::AStar(AdjList G, int src, int dst,
                                   std::function<double(int)> h){
  auto path = std::vector<int>();

  auto _h = h(1);

  return path;
}

std::vector<int> PathFinder::ALT(AdjList G, int src, int dst) {}
