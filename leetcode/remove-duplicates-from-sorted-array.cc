class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    int tail = 1;
    for(int i = 1; i < nums.size(); ++i) {
      if(nums[i] != nums[tail-1]) {
        nums[tail] = nums[i];
        tail += 1;
      }
    }
    return tail;
  }
};
