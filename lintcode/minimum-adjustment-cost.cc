class Solution {
 public:
  int MinAdjustmentCost(vector<int> A, int target) {
    int M = INT_MIN;
    for(auto & v : A) M = max(v, M);
    vector<vector<int>> dp(A.size() + 1, vector<int>(M+1, 0));
    int r = INT_MAX;
    for(int i = 1; i <= A.size(); ++i) {
      for(int j = 1; j <= M; ++j) {
        dp[i][j] = INT_MAX;
        int delta = abs(j - A[i-1]);
        int lb = max(1, j - target);
        int hb = min(M, j + target);
        for(int k = lb; k <= hb; ++k) {
          dp[i][j] = min(dp[i][j], dp[i-1][k]);
        }
        dp[i][j] += delta;
        if(i == A.size()) r = min(r, dp[i][j]);
      }
    }
    return r;
  }
};
