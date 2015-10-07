class Solution {
 public:
  // O(n*n) space, O(n*n) time
  int minCut(string s) {
    vector<int> D(s.size() + 1, 0);
    vector<vector<int>> P(s.size(), vector<int>(s.size(), 0));
    for(int i = 0; i <= s.size(); ++i) D[i] = s.size() - 1 - i;
    for(int i = s.size() - 1; i >= 0; --i) {
      for(int j = i; j < s.size(); ++j) {
        if(s[i] == s[j] && (j - i < 2 || P[i+1][j-1] == 1)) {
          P[i][j] = 1;
          D[i] = min(D[i], D[j+1] + 1);
        }
      }
    }
    return D[0];
  }
};
