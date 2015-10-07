class Solution {
 
 public:
  // f(n) = n*f(n-1)
  bool wordBreak2(string s, unordered_set<string>& wordDict) {
    for(int i = 0; i < s.size(); ++i) {
      if(wordDict.count(s.substr(0, i + 1)) && wordBreak2(s.substr(i + 1, s.size() - i - 1), wordDict)) return true;
    }
    return false;
  }

  // O(n*n)
  bool wordBreak(string s, unordered_set<string> & wordDict) {
    vector<int> table(s.size(), 0);
    table[0] = wordDict.count(s.substr(0, 1)) ? 1 : 0;
    for(int i = 1; i < s.size(); ++i) {
      if(wordDict.count(s.substr(0, i + 1))) {
        table[i] = 1;
        continue;
      }
      for(int j = i - 1; j >= 0; --j) {
        if(table[j] && wordDict.count(s.substr(j + 1, i - j))) {
          table[i] = 1;
          break;
        }
      }
    }
    return table.back();
  }
};
