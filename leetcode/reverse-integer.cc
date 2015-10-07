class Solution {
 public:
  int reverse(int x) {
    uint64_t result = 0;
    if(x == INT_MIN) return 0;
    int y = abs(x);
    while(y) {
      uint64_t v = result * 10 + y % 10;
      if(v > INT_MAX) return 0;
      result = v;
      y /= 10;
    }
    return x > 0 ? static_cast<int>(result) : -static_cast<int>(result);
  }
};
