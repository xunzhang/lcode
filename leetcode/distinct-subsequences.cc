class Solution {
 public:
  int numDistinct(string s, string t) {
    vector<vector<int>> table(s.size() + 1, vector<int>(t.size() + 1, 0));
    table[0][0] = 1;
    for(int i = 1; i <= s.size(); ++i) table[i][0] = 1;
    for(int i = 1; i <= t.size(); ++i) table[0][i] = 0;
    for(int i = 1; i <= s.size(); ++i) {
      for(int j = 1; j <= t.size(); ++j) {
        if(j > i) table[i][j] = 0;
        if(s[i-1] == t[j-1]) {
          table[i][j] = table[i-1][j-1] + table[i-1][j];
        } else {
          table[i][j] = table[i-1][j];
        }
      }
    }
    return table[s.size()][t.size()];
  }
};
