class Solution {
 public:
  /**
   * @param nums: a vector of integers
   * @return: nothing
   */
  void partitionArray(vector<int> &nums) {
    // write your code here
    int l = 0, r = nums.size() - 1;
    for(int i = 0; i < nums.size() && l < r;) {
      if(nums[i] % 2 == 1) {
        i ++; l ++;
      } else {
        swap(nums[i], nums[r--]);
      }
    }
  }
};

