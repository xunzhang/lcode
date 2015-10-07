class Solution {
 public:
  void bt(vector<int> & nums, vector<int> & visited, vector<int> & tmp, vector<vector<int>> & result) {
    if(tmp.size() == nums.size()) {
      result.push_back(tmp);
      return;
    }
    for(int i = 0; i < nums.size(); ++i) {
      if(visited[i] == 0) {
        visited[i] = 1;
        tmp.push_back(nums[i]);
        bt(nums, visited, tmp, result);
        tmp.pop_back();
        visited[i] = 0;
      }
    }
  }

  vector<vector<int>> permute(vector<int>& nums) {
    vector<int> tmp;
    vector<vector<int>> result;
    vector<int> visited(nums.size(), 0);
    bt(nums, visited, tmp, result);
    return result;
  }
};
