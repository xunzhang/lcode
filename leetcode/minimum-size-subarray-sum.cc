class Solution {
 public:
  // O(n) solution
  int minSubArrayLen(int s, vector<int>& nums) {
    int result = INT_MAX;
    int sum = 0, sz = 0, start = 0;
    for(size_t i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      sz += 1;
      while(sum >= s) {
        result = min(result, sz);
        sum -= nums[start];
        start ++;
        sz -= 1;
      }
    }
    return result == INT_MAX ? 0 : result;
  }

  // O(nlogn) solution
  int minSubArrayLen(int s, vector<int>& nums) {
    int sz = INT_MAX;
    if(nums.size() == 0) return 0;
    vector<int> sums(nums.size() + 1, 0);
    for (int i = 1; i <= nums.size(); i++) sums[i] = sums[i-1] + nums[i-1];
    for(int i = 0; i < sums.size(); ++i) {
      int j = binarySearch(sums, sums[i] + s, i + 1, sums.size() - 1);
      if(j == sums.size()) break;
      sz = min(sz, j - i);
    }
    return sz == INT_MAX ? 0 : sz;
  }

  int binarySearch(vector<int> & sums, int target, int l, int r) {
    while(l <= r) {
      int m = l + (r - l) / 2;
      if(sums[m] > target) {
        r = m - 1;
      } else if(sums[m] < target) {
        l = m + 1;
      } else {
        return m;
      }
    }
    return l;
  }
};
