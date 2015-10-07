class Solution {
 public:
  int sum(int n) {
    int r = 0;
    while(n) {
      int digit = n % 10;
      r += digit * digit;
      n /= 10;
    }
    return r;
  }
  bool isHappy(int n) {
    unordered_set<int> S;
    while(n != 1) {
      int v = sum(n);
      if(S.count(v)) return false;
      S.insert(v);
      n = v;
    }
    return true;
  }
};
