class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    for(int i = 0; i < nums.size();) {
      if(nums[i] != i + 1) {
        if(nums[nums[i]-1] == nums[i]) return nums[i];
        swap(nums[i], nums[nums[i]-1]);
      } else {
        ++i;
      }
    }
  }

  int findDuplicate(vector<int>& nums) {
    int slow = nums[0], fast = nums[nums[0]];
    while(slow != fast) { slow = nums[slow]; fast = nums[nums[fast]]; }
    slow = 0;
    while(slow != fast) { slow = nums[slow]; fast = nums[fast]; }
    return slow;
  }
};
