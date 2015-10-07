class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int red_last = -1, black_first = nums.size();
    int i = 0, sz = nums.size();
    while(i < sz) {
      if(nums[i] == 0) {
        swap(nums[i], nums[red_last+1]);
        red_last ++;
        i ++;
      } else if(nums[i] == 1) {
        i ++;
      } else {
        swap(nums[i], nums[black_first-1]);
        black_first --;
        sz -= 1;
      }
    }
  }
};
