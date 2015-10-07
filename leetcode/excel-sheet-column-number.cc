class Solution {
 public:
  int titleToNumber(string s) {
    int result = 0;
    int d = 1;
    for(int i = s.size() - 1; i >= 0; --i) {
      result += (s[i] - ('A' - 1)) * d;
      d *= 26;
    }
    return result;
  }
};
