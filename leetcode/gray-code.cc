class Solution {
 public:
  vector<int> grayCode(int n) {
    vector<int> result = {0};
    for(int round = 0; round < n; ++round) {
      for(int i = result.size() - 1; i >= 0; --i) {
        result.push_back(result[i] | (1 << round));
      }
    }
    return result;
  }
};
