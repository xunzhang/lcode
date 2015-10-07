class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    if(matrix.size() == 0) return result;
    int m = matrix.size(), n = matrix[0].size();
    int round = (min(m,n) + 1) / 2;
    for(int k = 0; k < round; ++k) {
      for(int i = k; i <= n - 1 - k; ++i) result.push_back(matrix[k][i]);
      for(int i = k + 1; i < m - 1 - k; ++i) result.push_back(matrix[i][n-1-k]);
      for(int i = n - 1 - k;  m - 1 - k != k && i >= k; --i) result.push_back(matrix[m-1-k][i]);
      for(int i = m - 2 - k; n - 1 - k != k && i > k; --i) result.push_back(matrix[i][k]);
    }
    return result;
  }
};
