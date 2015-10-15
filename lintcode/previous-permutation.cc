class Solution {

 public:
  /**
   * @param nums: An array of integers
   * @return: An array of integers that's previous permuation
   */
  vector<int> previousPermuation(vector<int> &nums) {
    // write your code here
    int i = nums.size() - 2;
    while(i >= 0 && nums[i] <= nums[i+1]) --i;
    if(i == -1) {
      sort(nums.begin(), nums.end());
      reverse(nums.begin(), nums.end());
      return nums;
    }
    reverse(nums.begin() + i + 1, nums.end());
    for(int k = i + 1; k < nums.size(); ++k) {
      if(nums[k] < nums[i]) {
        swap(nums[k], nums[i]);
        break;
      }
    }
    return nums;
  }
};

