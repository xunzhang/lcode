class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 0) return "";
    string prefix = strs[0];
    for(size_t i = 1; i < strs.size(); ++i) {
      int j = 0;
      for(; j < prefix.size(); ++j) {
        if(prefix[j] != strs[i][j])
          break;
      }
      prefix = prefix.substr(0, j);
    }
    return prefix;
  }
};
