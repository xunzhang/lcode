class Solution {
 public:
  int lengthOfLastWord(string s) {
    int k = s.size() - 1;
    while(k >= 0 && s[k] == ' ') k -= 1;
    int last = k;
    while(k >= 0 && s[k] != ' ') k -= 1;
    return last - k;
  }
};
