#include <queue>

class DoubleLinear {
public:
  static int dblLinear(int n) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> queue;
    queue.push(1);
    int last{0};
    
    for (int i{0}; i < n;) {
      if (last == queue.top()) {
        queue.pop();
        continue;
      }
      last = queue.top();
      queue.pop();
      queue.push(last * 2 + 1);
      queue.push(last * 3 + 1);
      i++;
    }
    return queue.top();
  }
};