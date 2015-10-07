class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    for(int i = 0; i < nums.size();) {
      if(nums[i] <= 0 || nums[i] == i + 1 || nums[i] > nums.size()) {
        i += 1;
      } else {
        if(nums[i] != nums[nums[i]-1]) {
          swap(nums[i],
               nums[nums[i]-1]);
        } else {
          i += 1;
        }
      }
    }
    int i = 0;
    for(;i < nums.size(); ++i) {
      if(nums[i] != i+1) return i+1;
    }
    return i+1;
  }
};
