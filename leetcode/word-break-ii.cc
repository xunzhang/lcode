class Solution {

 public:
  void bt(int indx, string & s, string tmp, vector<string> & solutions) {
    for(int fwd : table[indx]) {
      if(fwd == indx) {
        string ss = s.substr(0, fwd + 1); 
        reverse(ss.begin(), ss.end());
        string kk = tmp.size() == 0 ? tmp + ss : tmp + " " + ss; 
        reverse(kk.begin(), kk.end());
        solutions.push_back(kk);
      } else {
        string ss = s.substr(fwd + 1, indx - fwd);
        reverse(ss.begin(), ss.end());
        if(tmp.size() == 0) {
          bt(fwd, s, tmp + ss, solutions);
        } else {
          bt(fwd, s, tmp + " " + ss, solutions);
        }
      }   
    }   
  }
  
  vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    vector<string> solutions;
    table.resize(s.size(), vector<int>());
    if(wordDict.count(s.substr(0, 1))) table[0].push_back(0);
    for(int i = 1; i < s.size(); ++i) {
      for(int j = i; j >= 0; --j) {
        if(j == i) {
          if(wordDict.count(s.substr(0, j + 1))) table[i].push_back(j);
        } else {
          if(table[j].size() > 0 && wordDict.count(s.substr(j + 1, i - j))) {
            table[i].push_back(j);
          }
        }
      }
    }
    if(table[s.size()-1].size() == 0) return solutions;
    string tmp;
    bt(s.size() - 1, s, tmp, solutions);
    return solutions;
  }

 private:
  vector<vector<int>> table;
};
