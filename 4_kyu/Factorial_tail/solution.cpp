#include <cmath>
#include <map>
#include <vector>

std::vector<int> getPrimeFactors(int number) {
  std::vector<int> result;

  for (int i = 2; i <= sqrt(number); i++) {
    while (number % i == 0) {
      result.push_back(i);
      number /= i;
    }
  }
  if (number > 1) {
    result.push_back(number);
  }
  return result;
}

int Zeroes(int base, int number) {
  auto vec = getPrimeFactors(base);
  std::map<int, std::pair<int, int>> map;
  for (auto num : vec) {
    map[num].second++;
  }

  while (number > 1) {
    int temp = number;
    for (auto& pair : map) {
      while (temp % pair.first == 0) {
        temp /= pair.first;
        ++pair.second.first;
      }
    }
    --number;
  }
  int zeroesCount = map.begin()->second.first;
  for (const auto& pair : map) {
    auto temp = pair.second.first / pair.second.second;
    if (temp < zeroesCount) zeroesCount = temp;
  }
  return zeroesCount;
}