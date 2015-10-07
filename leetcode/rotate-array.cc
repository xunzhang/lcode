class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    if(k == 0) return;
    if(k >= nums.size()) return rotate(nums, k % nums.size());
    reverse(nums, 0, nums.size() - k - 1);
    reverse(nums, nums.size() - k, nums.size() - 1);
    reverse(nums, 0, nums.size() - 1);
  }

  void reverse(vector<int> & s, int i, int j) {
    while(i < j) { swap(s[i], s[j]); i++; j--; }
  }
};
