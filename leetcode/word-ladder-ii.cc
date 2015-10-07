class Solution {

 public:
  vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
    vector<vector<string>> allpaths, paths;
    queue<pair<int, vector<string>> > Q;
    Q.push(make_pair(1, vector<string>{beginWord}));
    if(wordList.count(beginWord)) wordList.erase(beginWord);
    int prev = 1;
    unordered_set<string> tmpWords;
    while(!Q.empty()) {
      auto pr = Q.front(); Q.pop();
      int layer = pr.first;
      auto path = pr.second;
      string word = path.back();
      if(layer != prev) {
        for(auto & wd : tmpWords) {
          wordList.erase(wd);
        }
        tmpWords.clear();
        prev = layer;
      }
      for(size_t i = 0; i < word.size(); ++i) {
        for(char ch = 'a'; ch <= 'z'; ++ch) {
          if(ch == word[i]) continue;
          char tmp = word[i];
          word[i] = ch;
          if(word == endWord) {
            path.push_back(endWord);
            allpaths.push_back(path);
          } else if(wordList.count(word)) {
            path.push_back(word);
            Q.push(make_pair(layer + 1, path));
            path.pop_back();
            tmpWords.insert(word);
          }
          word[i] = tmp;
        }
      }
    }
    int mlen = INT_MAX;
    for(auto & path : allpaths) mlen = min(mlen, static_cast<int>(path.size()));
    for(auto & path : allpaths) {
      if(path.size() == mlen) paths.push_back(path);

    }
    return paths;
  }
};
