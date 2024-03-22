#include <cmath>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

int last_digit(const std::list<int>& array) {
  if (array.empty()) {
    return 1;
  }

  int first = array.front() % 10;

  if (array.size() == 1 || first == 1) {
    return first;
  }

  std::unordered_map<int, std::vector<int>> map;
  map[2] = {6, 2, 4, 8};
  map[3] = {1, 3, 9, 7};
  map[4] = {6, 4, 6, 4};
  map[7] = {1, 7, 9, 3};
  map[8] = {6, 8, 4, 2};
  map[9] = {1, 9, 1, 9};

  int temp{1};
  bool isGood = false;
  auto it = std::prev(array.end());

  while (it != std::next(array.begin())) {
    isGood = (temp && *it > 1);
    if (*it > 0 && *it % 4 == 0) {
      isGood = true;
      temp = 4;
    } else if (temp && temp % 4 == 0) {
      temp = *it ? *it % 4 : 0;
    } else {
      temp = static_cast<int>(std::pow(*it % 4, temp % 4));
    }
    --it;
  }

  if (*it == 0) {
    if (temp != 0) {
      return 1;
    }
    return first;
  }

  if (first == 0 || first == 5 || first == 6) {
    return first;
  }

  if ((*it % 4 == 2 || *it % 4 == 0) && isGood) {
    return map[first][0];
  }

  temp = static_cast<int>(std::pow(*it % 4, temp % 4)) % 4;

  return map[first][temp];
}
