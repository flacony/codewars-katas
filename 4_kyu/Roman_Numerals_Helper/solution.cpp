#include <string>
#include <vector>

class RomanHelper {
private:
  std::vector<std::pair<std::string, int>> _numbers{
      {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100},
      {"XC", 90},  {"L", 50},   {"XL", 40}, {"X", 10},   {"IX", 9},
      {"V", 5},    {"IV", 4},   {"I", 1}};

public:
  std::string to_roman(unsigned int n) {
    if (n == 0) return "0";
    std::string result;
    
    for (const auto& pair : _numbers) {
      while (n >= static_cast<unsigned int>(pair.second)) {
        n -= pair.second;
        result += pair.first;
      }
    }
    
    return result;
  }

  int from_roman(std::string rn) {
    int result{0};
    
    for (const auto& pair : _numbers) {
      while (rn.compare(0, pair.first.length(), pair.first) == 0) {
        result += pair.second;
        rn = rn.substr(pair.first.length());
      }
    }
    
    return result;
  }
};

RomanHelper RomanNumerals;