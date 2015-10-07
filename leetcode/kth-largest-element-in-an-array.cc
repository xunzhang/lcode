class Solution {

 public:
  int partition(vector<int> & nums, int lo, int hi) {
    int i = lo, j = hi + 1;
    while(1) {
      while(nums[++i] < nums[lo]) {
        if(i == hi) break;
      }
      while(nums[--j] > nums[lo]) {
        if(j == lo) break;
      }
      if(i >= j) break;
      swap(nums[i], nums[j]);
    }
    swap(nums[lo], nums[j]);
    return j;
  }

  // O(N) with worst cast O(N*N)
  int findKthLargest(vector<int>& nums, int k) {
    random_shuffle(nums.begin(), nums.end());
    int lo = 0, hi = nums.size() - 1;
    k = nums.size() - k;
    while(lo < hi) {
      int j = partition(nums, lo, hi);
      if(j < k) {
        lo = j + 1;
      } else if(j > k) {
          hi = j - 1;
      } else {
        return nums[k];
      }
    }
    return nums[k];
  }
};
