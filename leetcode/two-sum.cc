// https://leetcode.com/problems/two-sum/
// O(n) space, O(n) time
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    unordered_map<int, int> D;
    for(size_t i = 0; i < nums.size(); ++i) D[nums[i]] = i;
    for(size_t i = 0; i < nums.size(); ++i) {
      int v = target - nums[i];
      if(!D.count(v)) continue;
      if(D[v] == i) continue;
      result.push_back(i+1);
      result.push_back(D[v]+1);
      return result;
    }
  }
};
