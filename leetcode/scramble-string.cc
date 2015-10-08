class Solution {

 public:
  bool isScramble_rec(string s1, string s2) {
    if(s1.size() != s2.size()) return false;
    if(s1.size() == 1) return s2 == s1;
    string tmp1 = s1, tmp2 = s2;
    sort(tmp1.begin(), tmp1.end());
    sort(tmp2.begin(), tmp2.end());
    if(tmp1 != tmp2) return false;
    int N = s1.size();
    for(int i = 1; i < N; ++i) {
      string a1 = s1.substr(0, i);
      string b1 = s1.substr(i, N - i);
      string a2 = s2.substr(0, i);
      string b2 = s2.substr(i, N - i);
      if(isScramble(a1, a2) && isScramble(b1, b2)) return true;
      a2 = s2.substr(i, N - i);
      b2 = s2.substr(N - i, i);
      if(isScramble(a1, b2) && isScramble(b1, a2)) return true;
    }
    return false;
  }

  bool isScramble(string s1, string s2) {
    if(s1.size() != s2.size()) return false;
    if(s1.size() == 1) return s2 == s1;
    string tmp1 = s1, tmp2 = s2;
    sort(tmp1.begin(), tmp1.end());
    sort(tmp2.begin(), tmp2.end());
    if(tmp1 != tmp2) return false;
    int N = s1.size();
    vector<vector<vector<char>>> table(N, vector<vector<char>>(N, vector<char>(N, 'x')));
    for(int i = 0; i < N; ++i) {
      for(int j = 0; j < N; ++j) {
        if(s1[i] == s2[j]) table[0][i][j] = 'o';
      }
    }
    for(int k = 2; k <= N; ++k) {
      for(int i = N - k; i >= 0; --i) {
        for(int j = N - k; j >= 0; --j) {
          for(int m = 1; m < k; ++m) {
            if(table[m-1][i][j] == 'o' && table[k-m-1][i+m][j+m] == 'o' || table[m-1][i][j+k-m] == 'o' && table[k-m-1][i+m][j] == 'o') {
              table[k-1][i][j] = 'o';
              break;
            }
          }
        }
      }
    }
    return table[N-1][0][0] == 'o';
  }
};
