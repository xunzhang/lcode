class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result(numRows);
    for(int i = 0; i < numRows; ++i) {
      for(int j = 0; j < i + 1; ++j) {
        if(j == 0) { result[i].push_back(1); continue; }
        if(j == i) { result[i].push_back(1); continue; }
        result[i].push_back(result[i-1][j-1] + result[i-1][j]);
      }
    }
    return result;
  }
};
