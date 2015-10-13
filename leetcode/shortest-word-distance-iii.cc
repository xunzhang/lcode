class Solution {

 public:
  int shortestWordDistance2(vector<string>& words, string word1, string word2) {
    unordered_map<string, vector<int>> M;
    for(int i = 0; i < words.size(); ++i) {
      if(words[i] == word1 || words[i] == word2) {
        M[words[i]].push_back(i);
      }
    }
    int dis = INT_MAX;
    if(word1 == word2) {
      for(int i = 0; i < M[word1].size() - 1; ++i) {
        dis = min(dis, M[word1][i+1] - M[word1][i]);
      }
      return dis;
    }
    int i = 0, j = 0;
    while(i < M[word1].size() && j < M[word2].size()) {
      dis = min(dis, abs(M[word1][i] - M[word2][j]));
      M[word1][i] < M[word2][j] ? i ++ : j ++;
    }
    return dis;
  }

  // O(1) space
  int shortestWordDistance(vector<string>& words, string word1, string word2) {
    int x = -1, y = -1, dis = INT_MAX;
    bool flag = (word1 == word2);
    for(int i = 0; i < words.size(); ++i) {
      if(words[i] == word1) x = i;
      if(flag) {
        if(x != -1 && y != -1 && x != y) {
          dis = min(dis, abs(x - y));
        }
      }
      if(words[i] == word2) y = i;
      if(!flag) {
        if(x != -1 && y != -1) {
          dis = min(dis, abs(x - y));
        }
      }
    }
    return dis;
  }
};
