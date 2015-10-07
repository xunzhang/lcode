class Solution {
  using ll = long long;
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if(t < 0 || k < 1) return false;
    unordered_map<ll, ll> b;
    for(int i = 0; i < nums.size(); ++i) {
      ll v = nums[i], j = (v - INT_MIN) / (t + 1LL);
      if(b.count(j) ||
         (b.count(j-1) && v - b[j-1] <= t) ||
         (b.count(j+1) && b[j+1] - v <= t)) return true;
      if(i >= k) b.erase((ll(nums[i-k]) - INT_MIN) / (t + 1LL));
      b[j] = v;
    }
    return false;
  }
};
