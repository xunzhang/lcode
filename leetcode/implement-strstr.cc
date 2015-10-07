class Solution {
 public:
  int strStr(string haystack, string needle) {
    if(needle.size() == 0) return 0;
    for(int i = 0; i < haystack.size(); ++i) {
      for(int j = 0; ; ++j) {
        if(j == needle.size()) return i;
        if(i + j > haystack.size() - 1) return -1;
        if(haystack[i+j] != needle[j]) break;
      }
    }
  }
};
