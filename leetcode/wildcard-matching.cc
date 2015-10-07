class Solution {

 public:
  bool isMatch2(string s, string p) {
    vector<vector<int>> table(p.size() + 1, vector<int>(s.size() +
    table[0][0] = 1;
    for(int j = 1; j <= p.size(); ++j) {
      char ch = p[j-1];
      table[j][0] = table[j-1][0] && ch == '*';
      for(int i = 1; i <= s.size(); ++i) {
        if(ch == '*') {
          table[j][i] = table[j-1][i] || table[j][i-1]; // match or not match
        } else {
          table[j][i] = table[j-1][i-1] && (ch == '?' || ch == s[i-1]);
        }
      }
    }
    return table[p.size()][s.size()] == 1;
  }

  bool isMatch(string s, string p) {
    vector<int> col(s.size() + 1, 0);
    vector<int> lastCol(s.size() + 1, 0);
    col[0] = 1;
    lastCol[0] = 1;
    for(int j = 1; j <= p.size(); ++j) {
      char ch = p[j-1];
      col[0] = col[0] && ch == '*';
      for(int i = 1; i <= s.size(); ++i) {
        if(ch == '*') {
          col[i] = col[i] || col[i-1];
        } else {
          col[i] = lastCol[i-1] && (ch == '?' || ch == s[i-1]);
        }
      }
      for(int i = 0; i <= s.size(); ++i) lastCol[i] = col[i];
    }
    return col.back() == 1;
  }
};
