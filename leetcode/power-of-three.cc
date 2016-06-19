class Solution {
 public:
  bool isPowerOfThree_loop(int n) {
    if(n == 0) return false;
    while(n % 3 == 0) {
      n /= 3;
    }
    return n == 1;
  }
  bool isPowerOfThree(int n) {
    int threeMax = 1162261467;
    return (n > 0) && (threeMax % n == 0);
  }
};
