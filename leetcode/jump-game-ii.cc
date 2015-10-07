class Solution {
 public:
  int jump(vector<int>& nums) {
    int far = 0;
    int explore = 0;
    int steps = 0;
    for(int i = 0; i < nums.size() && i <= far; ++i) {
      if(i > explore) {
        explore = far;
        steps += 1;
      }
      far = max(far, nums[i] + i);
    }
    return steps;
  }
};
