class Solution {

 public:
  bool shifted(string a, string b) {
    if(a.size() != b.size()) return false;
    if(a.size() == 0) return true;
    int delta = a[0] - b[0] < 0 ? a[0] - b[0] + 26 : a[0] - b[0];
    for(int i = 1; i < a.size(); ++i) {
      int tmp = a[i] - b[i] < 0 ? a[i] - b[i] + 26 : a[i] - b[i];
      if(tmp != delta) return false;
    }
    return true;
  }

  vector<vector<string>> groupStrings(vector<string>& strings) {
    vector<vector<string>> groups;
    if(strings.size() == 0) return groups;
    unordered_set<int> inside;
    for(int i = 0; i < strings.size(); ++i) {
      if(inside.count(i)) continue;
      inside.insert(i);
      vector<string> tmp = {strings[i]};
      for(int j = i + 1; j < strings.size(); ++j) {
        if(inside.count(j)) continue;
        if(shifted(strings[j], strings[i])) {
          inside.insert(j);
          tmp.push_back(strings[j]);
        }
      }
      groups.push_back(tmp);
    }
    for(auto & group : groups) sort(group.begin(), group.end());
    return groups;
  }
};
