class Solution {
 public:
  bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return false;
    unordered_map<char, int> D;
    for(auto & c : s) {
      D[c] += 1;
    }
    for(auto & c : t) {
      if(!D.count(c)) return false;
      D[c] -= 1;
      if(D[c] == 0) D.erase(c);
    }
    return true;
  }
};
