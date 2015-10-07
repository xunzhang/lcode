class Solution {
 public:
  int climbStairs(int n) {
    int fa = 0, fb = 1, f = 0;
    for(int i = 0; i < n; ++i) {
      f = fa + fb;
      fa = fb;
      fb = f;
    }
    return f;
  }
};
