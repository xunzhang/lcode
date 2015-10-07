class Solution {
 public:
  vector<string> anagrams(vector<string>& strs) {
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
};
