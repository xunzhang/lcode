class Solution {

 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.size() == 0) return 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int> > table(m, vector<int>(n, 0));
    int result = 0;
    for(int j = 0; j < n; ++j) {
      table[0][j] = matrix[0][j] == '1' ? 1 : 0;
      result = max(result, table[0][j]);
    }
    for(int i = 1; i < m; ++i) {
      table[i][0] = matrix[i][0] == '1' ? 1 : 0;
      result = max(result, table[i][0]);
    }
    for(int i = 1; i < m; ++i) {
      for(int j = 1; j < n; ++j) {
        if(matrix[i][j] == '1') {
          table[i][j] = min(table[i-1][j-1], min(table[i-1][j], table[i][j-1])) + 1;
          result = max(result, table[i][j]);
        }
      }
    }
    return result * result;
  }
};
