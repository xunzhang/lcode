class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    if(s3.size() != s1.size() + s2.size()) return false;
    vector<vector<int>> table(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    table[0][0] = 1;
    for(int i = 1; i <= s1.size(); ++i) {
      if(s1[i-1] == s3[i-1]) {
        table[i][0] = 1;
      } else {
        break;
      }
    }
    for(int i = 1; i <= s2.size(); ++i) {
      if(s2[i-1] == s3[i-1]) {
        table[0][i] = 1;
      } else {
        break;
      }
    }
    for(int i = 1; i <= s1.size(); ++i) {
      for(int j = 1; j <= s2.size(); ++j) {
        if(s3[i+j-1] == s1[i-1] && table[i-1][j] == 1) table[i][j] = 1;
        if(s3[i+j-1] == s2[j-1] && table[i][j-1] == 1) table[i][j] = 1;
      }
    }
    return table[s1.size()][s2.size()] == 1;
  }
};
