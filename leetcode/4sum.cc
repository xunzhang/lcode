// O(nlogn) + O(n^3)
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    if(nums.size() < 4) return result;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size() - 3; ++i) {
      if(i > 0 && nums[i] == nums[i-1]) continue;
      for(int j = i + 1; j < nums.size() - 2; ++j) {
        if(j > i + 1 && nums[j] == nums[j-1]) continue;
        int p1 = j + 1, p2 = nums.size() - 1;
        while(p1 < p2) {
          int v = nums[i] + nums[j] + nums[p1] + nums[p2];
          if(v == target) {
            result.push_back({nums[i], nums[j], nums[p1], nums[p2]});
            p1 ++; p2 --;
            while(p1 < p2 && nums[p1] == nums[p1-1]) p1 ++;
            while(p1 < p2 && nums[p2] == nums[p2+1]) p2 --;
          } else if(v < target) {
            p1 ++;
          } else {
            p2 --;
          }
        }
      } // for
    } // for
  }
};
