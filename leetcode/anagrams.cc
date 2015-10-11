class Solution {
 public:
  vector<string> anagrams_old(vector<string>& strs) {
    vector<string> result;
    unordered_map<string, int> D;
    for(size_t i = 0; i < strs.size(); ++i) {
      auto tmp = strs[i];
      sort(tmp.begin(), tmp.end());
      if(D.count(tmp)) {
        if(D[tmp] != -1) {
          result.push_back(strs[D[tmp]]);
          D[tmp] = -1;
        }
        result.push_back(strs[i]);
      } else {
        D[tmp] = i;
      }
    }
    return result;
  }

  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string> > result;
    unordered_set<string> S;
    unordered_map<string, int> indxM;
    for(int i = 0; i < strs.size(); ++i) {
      string tmp = strs[i];
      sort(tmp.begin(), tmp.end());
      if(S.count(tmp)) {
        result[indxM[tmp]].push_back(strs[i]);
      } else {
        indxM[tmp] = result.size();
        result.push_back(vector<string>{strs[i]});
        S.insert(tmp);
      }
    }
    for(auto & r : result) sort(r.begin(), r.end());
    return result;
  }
};
