class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> result;
    unordered_map<string, int> M, MM;
    for(auto & word : words) M[word] += 1;
    int L = words[0].size();
    for(int i = 0; i < s.size(); ++i) {
      string tmp = s.substr(i, L);
      MM = M;
      if(MM.count(tmp)) {
        for(int k = 0; k < words.size(); ++k) {
          if(!MM.count(tmp)) break;
          MM[tmp] --;
          if(MM[tmp] < 0) break;
          tmp = s.substr(i + (k + 1) * L, L);
          if(k == words.size() - 1) result.push_back(i);
        }
      }
      if(i + L * words.size() > s.size()) break;
    }
    return result;
  }
};
