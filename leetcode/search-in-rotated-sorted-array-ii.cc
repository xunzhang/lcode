class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    int s = 0, e = nums.size() - 1;
    while(s <= e) {
      int m = s + (e - s) / 2;
      if(nums[m] == target) {
        return true;
      } else if(nums[m] < nums[s]) {
        if(target > nums[m] && target <= nums[e]) {
          s = m + 1;
        } else {
          e = m - 1;
        }
      } else if(nums[m] > nums[s]) {
        if(target < nums[m] && target >= nums[s]) {
          e = m - 1;
        } else {
          s = m + 1;
        }
      } else {
        s = s + 1;
      }
    }
    return false;
  }
};
