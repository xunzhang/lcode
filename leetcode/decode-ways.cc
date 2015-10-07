class Solution {
 public:
  int numDecodings(string s) {
    if(s.size() == 0) return 0;
    if(s[0] == '0') return 0;
    vector<int> r(s.size() + 1, 0);
    r[0] = 1; r[1] = 1;
    for(int i = 1; i < s.size(); ++i) {
      if(s[i] == '0') {
        if(s[i-1] == '1' || s[i-1] == '2') {
          r[i+1] = r[i-1];
        } else {
          r[i+1] = 0;
        }
      } else {
        if(s[i-1] == '1' || (s[i-1] == '2' && s[i] > '0' && s[i] <= '6')) {
            r[i+1] = r[i-1];
        }
        r[i+1] += r[i];
      }
    }
    return r.back();
  }
};
