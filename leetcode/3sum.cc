// O(nlogn) + O(n^2)
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    if(nums.size() < 3) return result;
    sort(nums.begin(), nums.end()); // O(nlogn)
    for(int i = 0; i < nums.size() - 2 && nums[i] <= 0; ++i) {
      if(i > 0 && nums[i] == nums[i-1]) continue;
      int p1 = i + 1, p2 = nums.size() - 1;
      while(p1 < p2) {
        int v = nums[i] + nums[p1] + nums[p2];
        if(v == 0) {
          result.push_back({nums[i], nums[p1], nums[p2]});
          p1 ++; p2 --;
          while(p1 < p2 && nums[p1] == nums[p1-1]) p1 ++;
          while(p1 < p2 && nums[p2] == nums[p2+1]) p2 --;
        } else if(v < 0) {
            p1 ++;
        } else {
            p2 --;
        }
      }
    }
    return result;
  }

};
