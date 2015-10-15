class Solution {
 public:
  int partitionArray(vector<int> &nums, int k) {
    // write your code here
    int l = 0, r = nums.size();
    for(int i = 0; i < nums.size() && l < r;) {
      if(nums[i] < k) {
        l ++; i ++;
      } else {
        swap(nums[i], nums[--r]);
      }
    }
    return r;
  }
};

