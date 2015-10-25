class Solution {
 public:
  // 备忘录方法
  int dfs(vector<vector<int>>& A,vector<vector<int>> &dp,int row,int col) {
    if (dp[row][col] != 0) return dp[row][col];
    if (row + 1 < A.size() && A[row + 1][col] > A[row][col]) {
      dp[row][col] = max(dp[row][col],dfs(A,dp,row + 1,col));
    }
    if (row - 1 >= 0 && A[row - 1][col] > A[row][col]) {
      dp[row][col] = max(dp[row][col],dfs(A,dp,row - 1,col));
    }
    if (col - 1 >= 0 && A[row][col - 1] > A[row][col]) {
      dp[row][col] = max(dp[row][col],dfs(A,dp,row,col - 1));
    }
    if (col + 1 < A[0].size() && A[row][col + 1] > A[row][col]) {
      dp[row][col] = max(dp[row][col],dfs(A,dp,row,col + 1));
    }
    dp[row][col]++;
    return dp[row][col];
  }

  int longestIncreasingContinuousSubsequenceII(vector<vector<int>> & A)
  {
    if (A.size() == 0) return 0;
    int m = A.size(), n = A[0].size();
    vector<vector<int>> dp(m, vector<int>(n,0));
    int longest = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (dp[i][j] == 0) dp[i][j] = dfs(A,dp,i,j);
        longest = max(longest,dp[i][j]);
      }
    }
    return longest;
  }
};

