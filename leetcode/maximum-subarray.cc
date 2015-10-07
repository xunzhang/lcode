class Solution {
 public:
  int maxSubArray_dp(vector<int>& nums) {
    int v = 0;
    int maxSum = INT_MIN;
    for(int i = nums.size() - 1; i >= 0; --i) {
      v = max(nums[i] + v, nums[i]);
      maxSum = max(maxSum, v);
    }
    return maxSum;
  }

  int maxSubArray(vector<int>& nums) {
    return dac(nums, 0, nums.size() - 1);
  }

  int dac(vector<int> & nums, int l, int r) {
    if(l > r) return INT_MIN;
    int m = l + (r - l) / 2;
    int lmax = dac(nums, l, m - 1);
    int rmax = dac(nums, m + 1, r);
    int lpart = INT_MIN, rpart = INT_MIN;
    for(int i = m - 1, sum = 0; i >= l; --i) {
      sum += nums[i];
      lpart = max(lpart, sum);
    }
    for(int i = m + 1, sum = 0; i <= r; ++i) {
      sum += nums[i];
      rpart = max(rpart, sum);
    }
    lpart = lpart < 0 ? 0 : lpart;
    rpart = rpart < 0 ? 0 : rpart;
    return max(max(lmax, rmax), lpart + rpart + nums[m]);
  }
};
