#ifndef __DISJOINT_H__
#define __DISJOINT_H__

#include <vector>

class UnionFind {
private:
  std::vector<int> container_;

public:
  UnionFind(): container_{128} {}

  void MakeSet();
  void Find();
  void Union();
};


#endif