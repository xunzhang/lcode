class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<int>> r(m, vector<int>(n, 0));
    bool ob = false;
    for(int i = 0; i < n; ++i) {
      if(obstacleGrid[0][i] == 1) ob = true;
      r[0][i] = ob ? 0 : 1;
    }
    ob = false;
    for(int i = 0; i < m; ++i) {
      if(obstacleGrid[i][0] == 1) ob = true;
      r[i][0] = ob ? 0 : 1;
    }
    cout << r[0][0] << endl;
    cout << r[0][1] << endl;
    cout << r[1][0] << endl;
    for(int i = 1; i < m; ++i) {
      for(int j = 1; j < n; ++j) {
        if(obstacleGrid[i][j] == 1) { r[i][j] = 0; continue; }
        if(obstacleGrid[i-1][j] == 0) r[i][j] += r[i-1][j];
        if(obstacleGrid[i][j-1] == 0) r[i][j] += r[i][j-1];
      }
    }
    cout << r[1][1] << endl;
    return r[m-1][n-1];
  }
};
