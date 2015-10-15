class Solution {
 public:
  /**
   * Returns a index to the first occurrence of target in source,
   * or -1  if target is not part of source.
   * @param source string to be scanned.
   * @param target string containing the sequence of
   * characters to match.
   */
  int strStr(const char *source, const char *target) {
    // write your code here
    if(source == NULL || target == NULL) return -1;
    string S(source), T(target);
    if(T.size() == 0) return 0;
    for(int i = 0; i < S.size(); ++i) {
      for(int j = 0; ; ++j) {
        if(j == T.size()) return i;
        if(i + j >= S.size()) return -1;
        if(T[j] != S[i+j]) break;
      }
    }
    return -1;
  }
};
