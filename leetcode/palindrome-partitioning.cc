class Solution {
 public:
  bool isPalindrome(string & s) {
    int i = 0, j = s.size() - 1;
    while(i < j) {
      if(s[i] != s[j]) return false;
      i ++; j --;
    }
    return true;
  }

  void bt(string s, vector<string> & tmp, vector<vector<string>> & result) {
    if(s.size() == 0) {
      result.push_back(tmp);
      return;
    }
    for(int i = 0; i < s.size(); ++i) {
      string ss = s.substr(0, i + 1);
      if(isPalindrome(ss)) {
        tmp.push_back(ss);
        bt(s.substr(i + 1, s.size() - i - 1), tmp, result);
        tmp.pop_back();
      }
    }
  }

  vector<vector<string>> partition(string s) {
    vector<string> tmp;
    vector<vector<string>> result;
    bt(s, tmp, result);
    return result;
  }
};
