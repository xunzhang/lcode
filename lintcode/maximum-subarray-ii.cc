class Solution {
 public:
  /**
   * @param nums: A list of integers
   * @return: An integer denotes the sum of max two
   * non-overlapping subarrays
   */
  int maxTwoSubArrays(vector<int> nums) {
    vector<int> start(nums.size(), 0), end(nums.size(), 0);
    int maxEndingHere = nums[0], maxSofar = nums[0];
    start[0] = nums[0];
    for(int i = 1; i < nums.size(); ++i) {
      maxEndingHere = max(maxEndingHere + nums[i], nums[i]);
      maxSofar = max(maxSofar, maxEndingHere);
      start[i] = maxSofar;
    }
    maxSofar = nums.back();
    int maxStartingHere = nums.back();
    end.back() = nums.back();
    for(int i = nums.size() - 2; i >= 0; --i) {
      maxStartingHere = max(nums[i] + maxStartingHere, nums[i]);
      maxSofar = max(maxSofar, maxStartingHere);
      end[i] = maxSofar;
    }
    int r = INT_MIN;
    for(int i = 0; i < nums.size() - 1; ++i) {
      r = max(r, start[i] + end[i+1]);
    }
    return r;
  }
};


