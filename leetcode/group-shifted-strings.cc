class Solution {

 public:
  string getKey(string s) {
    if(s.size() == 0) return "";
    int delta = s[0] - 'a';
    for(int i = 0; i < s.size(); ++i) {
      if(s[i] - delta >= 'a') {
        s[i] = s[i] - delta;
      } else {
        s[i] = s[i] - delta + 26;
      }
    }
    return s;
  }

  // 类似anagrams
  vector<vector<string>> groupStrings(vector<string>& strings) {
    vector<vector<string>> groups;
    if(strings.size() == 0) return groups;
    unordered_set<string> S;
    unordered_map<string, int> indxM;
    for(int i = 0; i < strings.size(); ++i) {
      string key = getKey(strings[i]);
      if(S.count(key)) {
        groups[indxM[key]].push_back(strings[i]);
      } else {
        indxM[key] = groups.size();
        groups.push_back(vector<string>{strings[i]});
        S.insert(key);
      }
    }
    for(auto & group : groups) sort(group.begin(), group.end());
    return groups;
  }
};
