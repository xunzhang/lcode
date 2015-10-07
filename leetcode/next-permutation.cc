class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 2;
    while(i >= 0 && nums[i] >= nums[i+1]) i -= 1;
    if(i == -1) {
      reverse(nums.begin(), nums.end());
      return;
    }
    for(int k = nums.size() - 1; k > i; --k)
    {
      if(nums[k] > nums[i]) {
        swap(nums[k],
             nums[i]);
        break;
      }
    }
    reverse(nums.begin() + i + 1,
            nums.end());
  }
};
