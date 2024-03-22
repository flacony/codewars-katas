#include <iostream>
#include <unordered_set>
#include <vector>

using ullong = unsigned long long;

ullong solution(const std::vector<ullong>& arr) {
  if (arr.empty()) return 0;

  ullong result = arr[0];
  std::unordered_set<ullong> set;

  for (const auto& number : arr) {
    set.insert(number);
  }

  for (auto& number : set) {
    if (number == result) continue;

    ullong num1{number > result ? number % result : result % number};
    result = std::min(result, number);
    ullong temp;

    while (num1 != 0) {
      temp = num1;
      num1 = result % num1;
      result = temp;
    }
  }
  result *= arr.size();

  return result;
}