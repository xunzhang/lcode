class WordDistance {

 public:
  WordDistance(vector<string>& words) {
    for(int i = 0; i < words.size(); ++i) {
      M[words[i]].push_back(i);
    }
  }

  int shortest(string word1, string word2) {
    int dis = INT_MAX;
    int i = 0, j = 0;
    while(i < M[word1].size() && j < M[word2].size()) {
      dis = min(dis, abs(M[word1][i] - M[word2][j]));
      M[word1][i] < M[word2][j] ? i ++ : j ++;
    }
    return dis;
  }

 private:
  unordered_map<string, vector<int>> M;
};

// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
