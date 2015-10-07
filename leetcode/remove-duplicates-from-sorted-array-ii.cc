class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if(nums.size() < 2) return nums.size();
    int tail = 2;
    bool allow_twice = (nums[0] != nums[1]);
    for(int i = 2; i < nums.size(); ++i) {
      if(nums[i] != nums[tail-1]) {
        nums[tail] = nums[i];
        tail += 1;
        allow_twice = true;
      } else if(allow_twice) {
        nums[tail] = nums[i];
        tail += 1;
        allow_twice = false;
      }
    }
    return tail;
  }
};
