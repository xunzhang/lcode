class Solution {
 public:
  void rev(vector<int> & nums, int l, int r) {
    if(l >= r) return;
    while(l < r) {
      swap(nums[l], nums[r]);
      l ++; r --;
    }
  }

  void recoverRotatedSortedArray(vector<int> &nums) {
    // write your code here
    int mid = -1;
    for(int i = 0; i < nums.size() - 1; ++i) {
      if(nums[i] > nums[i+1]) { mid = i; break; }
    }
    if(mid == -1) return;
    rev(nums, 0, mid);
    rev(nums, mid + 1, nums.size() - 1);
    rev(nums, 0, nums.size() - 1);
  }
};

