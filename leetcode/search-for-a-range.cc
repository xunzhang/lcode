class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> range;
    int s = 0, e = nums.size();
    while(s <= e) {
      int m = s + (e - s) / 2;
      if(nums[m] == target) {
        int i = m - 1, j = m + 1;
        while(i >= 0 && nums[i] == target) i --;
        while(j < nums.size() && nums[j] == target) j ++;
        range = {i+1, j-1};
        return range;
      } else if(nums[m] < target) {
        s = m + 1;
      } else {
        e = m - 1;
      }
    }
    return {-1, -1};
  }
};
