class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    int result = nums[0] + nums[1] + nums[2];
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size() - 2; ++i) {
      int p1 = i + 1, p2 = nums.size() - 1;
      while(p1 < p2) {
        int v = nums[i] + nums[p1] + nums[p2];
        if(abs(v - target) < abs(result - target)) result = v;
        if(v == target) {
          return v;
        } else if(v < target) {
          p1 ++;
        } else {
          p2 --;
        }
      }
    } // for
    return result;
  }
};
