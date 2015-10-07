class Solution {
 public:
  int cvt(string s) {
    unordered_map<char, int> M;
    M['A'] = 0; M['C'] = 1; M['G'] = 2; M['T'] = 3;
    int r = 0;
    for(size_t i = 0; i < s.size(); ++i) {
      r += M[s[i]] * pow(4, i);
    }
    return r;
  }

  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> result;
    if(s.size() < 10) return result;
    unordered_map<int, int> D;
    for(size_t i = 0; i <= s.size() - 10; ++i) {
      auto tmp_str = s.substr(i, 10);
      auto tmp = cvt(tmp_str);
      if(D.count(tmp)) {
        if(D[tmp] != 0) {
          result.push_back(tmp_str);
          D[tmp] = 0;
        }
      } else {
        D[tmp] += 1;
      }
    }
    return result;
  }
};
