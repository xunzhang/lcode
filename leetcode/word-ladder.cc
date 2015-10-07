class Solution {

 public:
  int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    queue<pair<string, int> > Q;
    Q.push(make_pair(beginWord, 1));
    while(!Q.empty()) {
      auto pr = Q.front(); Q.pop();
      string word = pr.first; int layer = pr.second;
      for(size_t i = 0; i < word.size(); ++i) {
        for(char ch = 'a'; ch <= 'z'; ++ch) {
          if(ch == word[i]) continue;
          char tmp = word[i];
          word[i] = ch;
          if(word == endWord) {
            return layer + 1;
          } else if(wordList.count(word)) {
              Q.push(make_pair(word, layer + 1));
              wordList.erase(word);
            }
          word[i] = tmp;
        }
      }
    }
    return 0;
  }
};
