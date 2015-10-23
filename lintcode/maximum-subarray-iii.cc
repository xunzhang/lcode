class Solution {
 public:
  int maxSubArray(vector<int> nums, int k) {
    if(nums.size() < k) return 0;
    vector<vector<int>> global(k + 1, vector<int>(nums.size() + 1, 0));
    for(int t = 1; t <= k; ++t) {
      int local = INT_MIN;
      for(int i = t; i <= nums.size(); ++i) {
        local = max(local, global[t-1][i-1]) + nums[i-1];
        if(i == t) global[t][i] = local;
        else global[t][i] = max(global[t][i-1], local);
      }
    }
    return global[k][nums.size()];
  }
};

