class Solution {

 public:
  // O(n * n), 2sum smaller, 4sum smaller similar idea
  int threeSumSmaller(vector<int>& nums, int target) {
    int cnt = 0;
    if(nums.size() < 3) return cnt;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size() - 2; ++i) {
      int s = i + 1, e = nums.size() - 1;
      while(s < e) {
        if(nums[i] + nums[s] + nums[e] < target) {
          cnt += e - s;
          s ++;
        } else {
          e --;
        }
      }
    }
    return cnt;
  }
};
