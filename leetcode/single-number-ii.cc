class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    vector<int> bit(32, 0);
    int result = 0;
    // from lowest bit to highest bit
    for(int i = 0; i < 32; ++i) {
      for(size_t j = 0; j < nums.size(); ++j) {
        bit[i] += (nums[j] >> i) & 1;
      }
    }
    for(int i = 0; i < 32; ++i) {
      result += (bit[i] % 3) << i;
    }
    return result;
  }
};
