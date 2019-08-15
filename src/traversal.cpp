#include "traversal.hpp"

#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace org::kata;

// TODO: change order-return to tree return

std::vector<int> traversal::dfs(adj_list graph, int start_node) {
  std::vector<int> dfs_ordering;
  //std::map<int, int> dfs_tree;
  std::set<int> discovered;
  std::stack<int> next;
  next.push(start_node);
  while (!next.empty()) {
    int v = next.top();
    dfs_ordering.push_back(v);
    next.pop();
    if (discovered.find(v) == discovered.end()) {
      discovered.insert(v);
      for (auto &it: graph.outgoing(v)) {
        next.push(it);
        //dfs_tree.insert(std::pair<int, int>(it, v));
      }
    }
  }
}

std::vector<int> traversal::bfs(adj_list graph, int start_node) {
  std::vector<int> bfs_ordering;
  //std::map<int, int> bfs_tree;
  std::set<int> discovered;
  std::queue<int> next;
  next.push(start_node);
  while (!next.empty()) {
    int v = next.back();
    bfs_ordering.push_back(v);
    next.pop();
    if (discovered.find(v) == discovered.end()) {
      for (auto &it: graph.outgoing(v)) {
        discovered.insert(it);
        //bfs_tree.insert(std::pair<int, int>(it, v));
        next.push(it);
      }
    }
  }
}