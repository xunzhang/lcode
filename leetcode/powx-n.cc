class Solution {
 public:
  double myPow(double x, int n) {
    if(n == 0 || n == INT_MIN) return 1;
    if(n < 0) return 1. / myPow(x, -n);
    double half = myPow(x, n >> 1);
    double result = half * half;
    if(n & 1) result *= x;
    return result;
  }
  double myPow(double x, int n) {
    if(n == INT_MIN) return 1;
    int m = abs(n);
    double result = 1;
    while(m) {
      if(m & 1) result *= x;
      x *= x;
      m >>= 1;
    }
    return n > 0 ? result : 1. / result;
  }
};
