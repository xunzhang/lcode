class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int length = 0, start = 0;
    unordered_map<char, int> M;
    for(int i = 0; i < s.size(); ++i) {
      auto finder = M.find(s[i]);
      if(finder != M.end()) { start = max(finder->second + 1, start); }
        M[s[i]] = i;
        length = max(length, i - start + 1);
    }
    return length;
  }
};
