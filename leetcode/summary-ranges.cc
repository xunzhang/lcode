class Solution {
 public:
  string fmt(int l, int r) {
    if(l == r) return to_string(l);
    return to_string(l) + "->" + to_string(r);
  }
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> result;
    if(nums.size() == 0) return result;
    int prev = nums[0];
    size_t indx = 0;
    while(indx < nums.size()) {
      int next = (indx == nums.size() - 1) ? nums.back() + 2 : nums[indx+1];
      if(next - nums[indx] != 1) {
        result.push_back(fmt(prev, nums[indx]));
        prev = next;
      }
      indx ++;
    }
    return result;
  }
};
