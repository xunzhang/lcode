bool isMatch(char* s, char* p) {
  if(p[0] == '\0') { return s[0] == '\0'; }
  if(p[1] != '*') { // 如不是*就必须匹配
    if(s[0] != '\0' && (s[0] == p[0] || p[0] == '.')) { // s[0] != '\0'因为比如s="", p="."
      return isMatch(s + 1, p + 1);
    } else {
      return false;
    }
  } else {
    int i = 0;
    while(s[i] != '\0' && (s[i] == p[0] || p[0] == '.')) {
      if(isMatch(s + i, p + 2)) { return true; } // 不匹配这一个
      i ++; // 匹配这一个
    }
    return isMatch(s+i, p+2);
  }
}

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
