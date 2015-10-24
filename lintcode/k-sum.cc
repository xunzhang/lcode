// dp[i][j][v] = dp[i-1][j][v] + dp[i-1][j-1]v-A[i-1][], O(n * k * target)
// 如果target负数，则需要进一步改进
class Solution {
 public:
  /**
   * @param A: an integer array.
   * @param k: a positive integer (k <= length(A))
   * @param target: a integer
   * @return an integer
   */
  int kSum(vector<int> A, int k, int target) {
    int n = A.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(target+1, 0)));
    for(int i = 1; i <= n; i++) {
      if (A[i-1] <= target) {
        for(int j = i; j <=n; j++) {
          dp[j][1][A[i-1]] = 1;
        }
      }
    }
    for(int i = 1; i <= n; i++) {
      for(int j = min(i, k); j > 1; j--) {
        for(int p = 0; p <= target; p++) {
          dp[i][j][p] = dp[i-1][j][p];
          if (p-A[i-1] >= 0) {
            dp[i][j][p] += dp[i-1][j-1][p-A[i-1]];
          }
        }
      }
    }
    return dp[n][k][target];
  }
};

