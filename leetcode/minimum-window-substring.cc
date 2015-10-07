class Solution {
 public:
  string minWindow(string s, string t) {
    unordered_map<char, int> M;
    int minlen = INT_MAX, minStart = 0;
    for(auto & ch : t) M[ch] += 1;
    int D = 0, start = 0;
    for(int i = 0; i < s.size(); ++i) {
      if(M.count(s[i])) {
        M[s[i]] -= 1;
        if(M[s[i]] >= 0) D ++;
        while(D == t.size()) {
          if(i - start + 1 < minlen) { minlen = min(minlen, i - start + 1); minStart = start; }
          if(M.count(s[start])) {
            M[s[start]] ++;
            if(M[s[start]] > 0) D--;
          }
          start ++;
        }
      }
    }
    if(minlen == INT_MAX) return "";
    return s.substr(minStart, minlen);
  }
};
