#include <algorithm>
#include <iostream>
#include <vector>

int sum_intervals(std::vector<std::pair<int, int>> intervals) {
  if (intervals.empty()) {
    return 0;
  }

  std::sort(intervals.begin(), intervals.end(),
            [](std::pair<int, int> a, std::pair<int, int> b) {
              return a.first < b.first;
            });

  int intervalLength = 0;
  int intervalStart = intervals[0].first;
  int intervalEnd = intervals[0].second;

  for (const auto& pair : intervals) {
    if (pair.first <= intervalEnd) {
      intervalEnd = std::max(pair.second, intervalEnd);
    } else {
      intervalLength += intervalEnd - intervalStart;

      intervalStart = pair.first;
      intervalEnd = pair.second;
    }
  }

  intervalLength += intervalEnd - intervalStart;

  return intervalLength;
}