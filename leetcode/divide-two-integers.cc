class Solution {
 public:
  long long foo(long long x, long long y) {
    if(x < y || x == 0) return 0;
    long long r = 0, y_in = y, cnt = 0;
    while(x >= y) {
      r += 1 << cnt;
      x -= y;
      y *= 2;
      cnt += 1;
    }
    return r + foo(x, y_in);
  }

  int divide(int dividend, int divisor) {
    if(dividend == 0) return 0;
    bool negative = false;
    if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) negative = true;
    long long x = abs(static_cast<long long>(dividend)), y = abs(static_cast<long long>(divisor));
    long long result = foo(x, y);
    if(result > INT_MAX) return negative ? INT_MIN : INT_MAX;
    return negative ? -static_cast<int>(result) : static_cast<int>(result);
  }
};
