#include <vector>

std::vector<int> snail(const std::vector<std::vector<int>>& snail_map) {
  int size = snail_map.size();

  std::vector<int> result;

  for (int k{0}; k < size / 2; ++k) {
    for (int i{k}; i < size - k; ++i) {
      result.push_back(snail_map[k][i]);
    }

    for (int i{k + 1}; i < size - k; ++i) {
      result.push_back(snail_map[i][size - 1 - k]);
    }

    for (int i{size - 2 - k}; i >= k; --i) {
      result.push_back(snail_map[size - 1 - k][i]);
    }

    for (int i{size - 2 - k}; i > k; --i) {
      result.push_back(snail_map[i][k]);
    }
  }

  if (size % 2 != 0) {
    if (!snail_map[size / 2].empty())
      result.push_back(snail_map[size / 2][size / 2]);
  }
  
  return result;
}