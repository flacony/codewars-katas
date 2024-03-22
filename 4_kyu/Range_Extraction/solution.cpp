#include <string>
#include <vector>

std::string range_extraction(std::vector<int> args) {
  std::string result;

  for (int i{0}; i < args.size() - 1;) {
    result += std::to_string(args[i]);
    int len{0};
    int last = args[i];
    ++i;
    while (i + len < args.size() && args[i + len] - last == 1) {
      last = args[i + len];
      ++len;
    }
    i += len > 0 ? len - 1 : len;
    result += (len > 1 ? "-" : ",");
  }
  result += std::to_string(args.back());
  return result;
}