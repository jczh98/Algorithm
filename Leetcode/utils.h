#pragma once

#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

template <typename T>
std::string to_string(const std::vector<T> &vec) {
  std::stringstream ss;
  ss << "[";
  for (int i = 0; i < vec.size(); i++) {
    ss << vec[i] << ((i == vec.size() - 1) ? "" : ", ");
  }
  ss << "]";
  return ss.str();
}
