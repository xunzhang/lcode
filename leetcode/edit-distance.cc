class Solution {
 public:
  int minDistance(string word1, string word2) {
    if(word1.size() == 0) return word2.size();
    if(word2.size() == 0) return word1.size();
    vector<vector<int>> r(word1.size(), vector<int>(word2.size(), 0));
    r[0][0] = word1[0] == word2[0] ? 0 : 1;
    bool flag = false;
    for(int i = 0; i < word1.size(); ++i) {
      if(word1[i] == word2[0]) flag = true;
      r[i][0] = flag ? i : i + 1;
    }
    flag = false;
    for(int i = 0; i < word2.size(); ++i) {
      if(word2[i] == word1[0]) flag = true;
      r[0][i] = flag ? i : i + 1;
    }
    for(int i = 1; i < word1.size(); ++i) {
      for(int j = 1; j < word2.size(); ++j) {
        if(word1[i] == word2[j]) {
          r[i][j] = r[i-1][j-1];
        } else {
          int v = min(r[i-1][j] + 1, r[i][j-1] + 1);
          r[i][j] = min(r[i-1][j-1] + 1, v);
        }
      }
    }
    return r[word1.size()-1][word2.size()-1];
  }

};
