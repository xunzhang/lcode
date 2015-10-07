class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> result(n, vector<int>(n, 0));
    int cnt = 1;
    int round = (n + 1) / 2;
    for(int k = 0; k < round; ++k) {
      for(int i = k; i <= n - 1 - k; ++i) { result[k][i] = cnt; cnt ++; }
      for(int i = k + 1; i < n - 1 - k; ++i) { result[i][n-1-k] = cnt; cnt ++; }
      for(int i = n - 1 - k;  n - 1 - k != k && i >= k; --i) { result[n-1-k][i] = cnt; cnt ++; }
      for(int i = n - 2 - k; n - 1 - k != k && i > k; --i) { result[i][k] = cnt; cnt ++; }
    }
    return result;
  }
};
