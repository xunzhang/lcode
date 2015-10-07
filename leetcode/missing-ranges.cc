class Solution {
 public:
  vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<string> result;
    int prev = lower - 1;
    size_t indx = 0;
    while(indx <= nums.size()) {
      int curr = indx == nums.size() ? upper + 1 : nums[indx];
      if(curr - prev > 1) {
        result.push_back(fmt(prev + 1, curr - 1));
      }
      prev = curr;
      indx ++;
    }
    return result;
  }
  string fmt(int l, int r) {
    if(l == r) return to_string(l);
    return to_string(l) + "->" + to_string(r);
  }
};
