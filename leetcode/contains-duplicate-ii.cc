class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> M;
    for(int i = 0; i < nums.size(); ++i) {
      auto finder = M.find(nums[i]);
      if(finder != M.end()) {
        if(i - M[nums[i]] <= k) return true;
      }
      M[nums[i]] = i;
    }
    return false;
  }
};
