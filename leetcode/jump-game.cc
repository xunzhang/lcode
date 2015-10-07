class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int far = 0;
    for(int i = 0; i < nums.size() && i <= far; ++i) {
      far = max(far, i + nums[i]);
    }
    return far >= nums.size() - 1;
  }
};
