class Solution {

 public:
  void wiggleSort(vector<int>& nums) {
    if(nums.size() < 2) return;
    if(nums[0] > nums[1]) swap(nums[0], nums[1]);
    for(int i = 2; i < nums.size(); ++i) {
      if(i % 2 == 0) {
        if(nums[i] > nums[i-1]) swap(nums[i], nums[i-1]);
      } else {
        if(nums[i] < nums[i-1]) swap(nums[i], nums[i-1]);
      }
    }
  }
};
