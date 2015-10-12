class Solution {

 public:
  string alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> M, rM;
    unordered_set<char> S;
    for(auto & word : words) {
      for(int i = 0; i < word.size(); ++i) {
        S.insert(word[i]);
      }
    }
    for(int i = 0; i < words.size() - 1; ++i) {
      for(int j = 0; j < words[i].size(); ++j) {
        if(words[i][j] != words[i+1][j]) {
          M[words[i][j]].insert(words[i+1][j]);
          rM[words[i+1][j]].insert(words[i][j]);
          break;
        }
      }
    }
    string rule;
    unordered_set<char> record;
    while(1) {
      bool empty = true;
      for(auto & key : S) {
        if(record.count(key)) continue;
        if(!rM.count(key)) {
          empty = false;
          rule.push_back(key);
          for(auto & ch : M[key]) {
            rM[ch].erase(key);
            if(rM[ch].size() == 0) rM.erase(ch);
          }
          record.insert(key);
        }
      }
      if(empty){
        if(rule.size() != S.size()) return "";
        else break;
      }
    }
    return rule;
  }
};
