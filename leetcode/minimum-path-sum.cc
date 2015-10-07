// O(mn)
class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> result(grid);
    for(int i = 1; i < m; ++i) { result[i][0] = result[i-1][0] + grid[i][0]; }
    for(int i = 1; i < n; ++i) { result[0][i] = result[0][i-1] + grid[0][i]; }
    for(int i = 1; i < m; ++i) {
      for(int j = 1; j < n; ++j) {
        result[i][j] = min(result[i-1][j] + grid[i][j],
                          result[i][j-1] + grid[i][j]);
      }
    }
    return result[m-1][n-1];
  }
};
