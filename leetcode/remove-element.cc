class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    if(nums.size() == 0) return 0;
    int i = 0, last = nums.size() - 1;
    while(i <= last) {
      if(nums[i] == val) {
        swap(nums[i],
             nums[last]);
        last -= 1;
      } else {
        i ++;
      }
    }
    return last + 1;
  }
};
