class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    set<vector<int>> tmp_result;
    int sz = 2 << (nums.size() - 1);
    for(int i = 0; i < sz; ++i) {
      vector<int> tmp;
      for(size_t j = 0; j < nums.size(); ++j) {
        if((i >> j) & 1) {
          tmp.push_back(nums[j]);
        }
      }
      tmp_result.insert(tmp);
    }
    for(auto & tmp : tmp_result) {
      result.push_back(tmp);
    }
    return result;
  }
};
