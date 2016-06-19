class Solution {
 public:
  string reverseString(string s) {
    string r; r.resize(s.size());
    for(int i = s.size() - 1; i >= 0; --i) {
      r[s.size()-1-i] = s[i];
    }
    return r;
  }
};
