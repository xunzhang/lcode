class Solution {

 public:
  int foo(vector<int> & nums) {
    if(nums.size() == 0) return 0;
    if(nums.size() == 1) return nums[0];
    vector<int> table(nums.size() + 1, 0);
    table[0] = 0; table[1] = nums[0];
    int maxMoney = nums[0];
    for(int i = 2; i <= nums.size(); ++i) {
      table[i] = max(table[i-1], table[i-2] + nums[i-1]);
      maxMoney = max(maxMoney, table[i]);
    }
    return maxMoney;
  }

  int rob(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    if(nums.size() == 1) return nums[0];
    vector<int> nums2(nums.begin() + 1, nums.end());
    vector<int> nums3(nums.begin(), nums.end() - 1);
    return max(foo(nums2), foo(nums3));
  }
};
