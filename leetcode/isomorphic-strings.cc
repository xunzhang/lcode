class Solution {

 public:
  bool foo(string s, string t) {
    unordered_map<char, char> M;
    for(int i = 0; i < s.size(); ++i) {
      if(M.count(s[i]) && M[s[i]] != t[i]) return false;
      M[s[i]] = t[i];
    }
    return true;
  }

  bool isIsomorphic(string s, string t) {
    if(s.size() != t.size()) return false;
    return foo(s, t) && foo(t, s);
  }
};
