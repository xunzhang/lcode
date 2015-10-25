class Solution {
 public:
  /**
   * @param nums: a list of integers
   * @return: A integer denote the sum of minimum subarray
   */
  int minSubArray(vector<int> nums) {
    // write your code here
    int v = nums[0];
    int r = nums[0];
    for(int i = 1; i < nums.size(); ++i) {
      v = min(v + nums[i], nums[i]);
      r = min(r, v);
    }
    return r;
  }
};


