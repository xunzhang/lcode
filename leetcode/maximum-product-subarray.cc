class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int maxP = nums[0], f = nums[0], g = nums[0];
    for(int i = 1; i < nums.size(); ++i) {
      int v1 = f * nums[i], v2 = g * nums[i];
      f = min(min(v1, v2), nums[i]);
      g = max(max(v1, v2), nums[i]);
      maxP = max(maxP, g);
    }
    return maxP;
  }
};
