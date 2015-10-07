class Solution {
 public:
  bool isPalindrome(int x) {
    if(x < 0) return false;
    long long m = 1;
    while(m <= x) m *= 10;
    m /= 10;
    while(m > 1) {
      int l = x / m;
      int r = x % 10;
      if(l != r) return false;
      x = (x - l * m) / 10;
      m /= 100;
    }
    return true;
  }
};
