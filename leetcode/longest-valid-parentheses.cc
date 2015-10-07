class Solution {
 public:
  // T[i] 表示以s[i]开头的最长substr的长度
  int longestValidParentheses(string s) {
    if(s.size() <= 1) return 0;
    int maxlen = INT_MIN;
    vector<int> T(s.size(), 0);
    for(int i = s.size() - 2; i >= 0; --i) {
      if(s[i] == ')') {
        int indx = i + T[i+1] + 1;
        if(indx < s.size() && s[indx] == ')') {
          T[i] = T[i+1] + 2;
          if(indx + 1 < s.size()) T[i] += T[indx+1];
        } 
      }
      maxlen = max(maxlen, T[i]);
    }
    return maxlen;
  }
};
