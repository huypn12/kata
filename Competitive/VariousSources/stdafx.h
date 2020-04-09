#pragma once

#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

template<typename T> void PrintVector(const std::vector<T> &V) {
  std::ostringstream oss;
  oss << "[";
  for (auto i = 0; i < V.size(); ++i) {
    const char *sep = ",";
    if (i == V.size() - 1) {
      sep = "";
    }
    oss << V[i] << sep;
  }
  oss << "]";

  std::cout << oss.str() << std::endl;
}
