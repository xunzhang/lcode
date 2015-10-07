class Solution {
 public:
  string expand(string & s, int a, int b) {
    while(a >= 0 && b < s.size() && s[a] == s[b]) { a --; b ++; }
    return s.substr(a + 1, b - a - 1);
  }

  string longestPalindrome(string s) {
    string longPalindrome = s.substr(0, 1);
    for(int i = 0; i < s.size() - 1; ++i) {
      string tmp1 = expand(s, i, i);
      string tmp2 = expand(s, i, i + 1);
      if(tmp1.size() > longPalindrome.size()) longPalindrome = tmp1;
      if(tmp2.size() > longPalindrome.size()) longPalindrome = tmp2;
    }
    return longPalindrome;
  }
};
