class Solution {
 public:
  /**
   * @param nums: The integer array
   * @return: The length of LIS (longest increasing subsequence)
   */
  int longestIncreasingSubsequence(vector<int> nums) {
    // write your code here
    vector<int> nums2 = nums;
    sort(nums2.begin(), nums2.end());
    return longestCommonSubsequence(nums, nums2);
  }

  int longestCommonSubsequence(vector<int> & A, vector<int> & B) {
    // write your code here
    if(A.size() == 0 || B.size() == 0) return 0;
    int m = A.size(), n = B.size();
    vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));
    for(int i = 0; i <= m; ++i) {
      for(int j = 0; j <= n; ++j) {
        if(i == 0 || j == 0) table[i][j] = 0;
        else {
          if(A[i-1] == B[j-1]) table[i][j] = table[i-1][j-1] + 1;
          else table[i][j] = max(table[i][j-1], table[i-1][j]);
        }
      }
    }
    return table[m][n];
  }
};
