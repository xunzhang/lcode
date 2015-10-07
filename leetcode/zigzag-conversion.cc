class Solution {
 public:
  string convert(string s, int numRows) {
    if(numRows >= s.size() || numRows == 1) return s;
    string result;
    int t = (numRows - 1) * 2;
    for(int i = 0; i < numRows; ++i) {
      if(i == 0 || i == numRows - 1) {
        for(int j = i; j < s.size(); j += t) {
          result.push_back(s[j]);
        }
      } else {
        int interval = i * 2;
        for(int j = i; j < s.size(); j += interval) {
          result.push_back(s[j]);
          interval = t - interval;
        }
      }
    }
    return result;
  }
};
