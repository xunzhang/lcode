class Solution {
 public:
  /**
   * @param nums: A list of integers
   * @return: An integer indicate the value of maximum difference
   * between two
   *          Subarrays
   */
  int maxDiffSubArrays(vector<int> nums) {
    // write your code here
    vector<int> startMin(nums.size(), 0), startMax(nums.size(), 0);
    vector<int> endMin(nums.size(), 0), endMax(nums.size(), 0);
    for(int i = 0; i < nums.size(); ++i) {
      endMax[i] = i == 0 ? nums[0] : max(endMax[i-1] + nums[i], nums[i]);
      endMin[i] = i == 0 ? nums[0] : min(endMin[i-1] + nums[i], nums[i]);
    }
    for(int i = nums.size() - 1; i >= 0; --i) {
      startMin[i] = (i == nums.size() - 1) ? nums.back() : min(startMin[i+1] + nums[i], nums[i]);
      startMax[i] = (i == nums.size() - 1) ? nums.back() : max(startMax[i+1] + nums[i], nums[i]);
    }
    int r = INT_MIN;
    for(int i = nums.size() - 2; i >= 0; --i) {
      r = max(r, abs(endMax[i] - startMin[i+1]));
      r = max(r, abs(endMin[i] - startMax[i+1]));
    }
    return r;
  }
};

