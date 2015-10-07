class Solution {
 public:
  bool containsDuplicate2(vector<int>& nums) {
    unordered_set<int> S;
    for(auto & num : nums) {
      if(S.count(num)) return true;
      S.insert(num);
    }
    return false;
  }

  bool containsDuplicate(vector<int>& nums) {
    if(nums.size() <= 1) return false;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size() - 1; ++i) {
      if(nums[i] == nums[i+1]) return true;
    }
    return false;
  }
};
