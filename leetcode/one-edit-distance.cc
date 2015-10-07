class Solution {
 public:
  bool isOneEditDistance(string s, string t) {
    if(s.size() > t.size()) return isOneEditDistance(t, s);
    if(s.size() == t.size()) {
      int cnt = 0;
      for(int i = 0; i < s.size(); ++i) {
        if(s[i] != t[i]) cnt += 1;
      }
      return cnt == 1;
    } else {
      if(s.size() + 1 != t.size()) return false;
      bool flag = true;
      for(int i = 0, j = 0; i < s.size(); ++i, ++j) {
        if(s[i] != t[j]) {
          if(flag) {
            flag = false;
            i -= 1;
            continue;
          } else {
            return false;
          }
        }
      }
      return true;
    }
  }
};
