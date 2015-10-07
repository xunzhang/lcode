class Solution {
 public:
  void reverse(string &s, int i, int j) {
    while(i < j) { swap(s[i], s[j]); i ++; j --; }
  }

  void reverseWords(string &s) {
    reverse(s, 0, s.size() - 1);
    int indx = 0, i = 0;
    while(i < s.size()) {
      while(i < s.size() && s[i] == ' ') i ++;
      int j = i + 1;
      while(j < s.size() && s[j] != ' ') j ++;
      j -= 1;
      reverse(s, i, j);
      for(int k = i; k < s.size() && k <= j + 1; ++k) s[indx++] = s[k];
      i = j + 2;
    }
    if(s[indx-1] == ' ') {
      s = s.substr(0, indx - 1);
    } else {
      s = s.substr(0, indx);
    }
  }
};
