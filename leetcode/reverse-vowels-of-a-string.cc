class Solution {
 public:
  string reverseVowels(string s) {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    string r = s; r.resize(s.size());
    int st = 0, en = s.size() - 1;
    // O(s.size()) total
    while(st <= en) {
      if(vowels.count(s[st])) {
        while(st <= en) {
          if(vowels.count(s[en])) {
            // swap here
            r[st] = s[en];
            r[en] = s[st];
            st ++; en --;
            break;
          } else {
            r[en] = s[en];
            en --;
          }
        }
      } else {
        r[st] = s[st];
        st ++;
      }
    }
    return r;
  }
};
