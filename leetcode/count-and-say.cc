class Solution {
 public:
  string countAndSay(int n) {
    string result = "1";
    for(int k = 0; k < n - 1; ++k) {
      string tmp;
      int cnt = 1;
      char ch = result[0];
      for(int i = 1; i < result.size(); ++i) {
        if(result[i] != ch) {
          tmp.push_back('0' + cnt);
          tmp.push_back(ch);
          cnt = 1;
          ch = result[i];
        } else {
          cnt += 1;
        }
      }
      tmp.push_back('0' + cnt);
      tmp.push_back(ch);
      result = tmp;
    }
    return result;
  }
};
