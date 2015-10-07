class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if(n == 0) return false;
    if((n >> 31) & 1) return false;
    return (n & (n - 1)) == 0;
  }
};
