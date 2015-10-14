class Solution {

 public:
  bool foo(string p, string s, unordered_map<char, string> & M, unordered_set<string> & S) {
    if(p.size() == 0) return s.size() == 0;
    if(s.size() == 0) return p.size() == 0;
    for(int i = 0; i < s.size(); ++i) {
      string pat = p.substr(1, p.size() - 1);
      string sa = s.substr(0, i + 1), sb = s.substr(i + 1, s.size() - i - 1);
      if(M.count(p[0])) {
        if(sa == M[p[0]] && foo(pat, sb, M, S)) return true;
        else if(M[p[0]][0] != sa[0]) return false;
      } else if(!S.count(sa)){
          M[p[0]] = sa;
          S.insert(sa);
          if(foo(pat, sb, M, S)) return true;
          M.erase(p[0]);
          S.erase(sa);
        }
    }
    return false;
  }

  bool wordPatternMatch(string pattern, string str) {
    if(pattern.size() == 0) return str.size() == 0;
    if(pattern.size() == 1) return str.size() > 0;
    if(str.size() == 0) return pattern.size() == 0;
    for(int i = 0; i < str.size(); ++i) {
      unordered_map<char, string> M;
      unordered_set<string> S;
      string pat = pattern.substr(1, pattern.size() - 1);
      string stra = str.substr(0, i + 1), strb = str.substr(i + 1, str.size() - i - 1);
      M[pattern[0]] = stra; S.insert(stra);
      if(foo(pat, strb, M, S)) return true;
    }
  return false;
  }
};
