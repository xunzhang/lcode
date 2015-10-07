class Solution {

 public:
  int lengthOfLongestSubstringTwoDistinct(string s) { return foo(s, 2); }

  int foo(string s, int KD) {
    int len = 0, start = 0, D = 0;
    vector<char> count(256, 0);
    for(int i = 0; i < s.size(); ++i) {
      if(count[s[i]] == 0) D++;
      count[s[i]] ++;
      while(D > KD) {
        count[s[start]] -= 1;
        if(count[s[start]] == 0) D--;
        start ++;
      }
      len = max(len, i - start + 1);
    }
    return len;
  }
};
