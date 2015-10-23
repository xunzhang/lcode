class Solution {
 public:
  bool isMatch(const char *s, const char *p) {
    string S = s, P = p;
    vector<vector<int>> matchTable(S.size() + 1, vector<int>(P.size() + 1, 0));
    matchTable[0][0] = 1;
    for(int j = 1; j < P.size(); j += 2) {
      if(P[j] == '*') {
        matchTable[0][j+1] = 1;
      } else {
        break;
      }
    }
    for(int i = 1; i <= S.size(); ++i) {
      for(int j = 1; j <= P.size(); ++j) {
        if(P[j-1] != '*') { matchTable[i][j] = matchTable[i-1][j-1] && (S[i-1] == P[j-1] || P[j-1] == '.');
        } else {
          matchTable[i][j] = matchTable[i][j-2] || ((S[i-1] == P[j-2] || P[j-2] == '.') && matchTable[i-1][j]);
        }
      }
    }
    return matchTable[S.size()][P.size()] == 1;
  }
};
