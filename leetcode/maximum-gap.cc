class Solution {
 public:
  int maximumGap(vector<int>& nums) {
    if(nums.size() < 2) return 0;
    int result = INT_MIN;
    int m = INT_MAX, M = INT_MIN;
    for(auto & num : nums) {
      m = min(num, m);
      M = max(num, M);
    }
    int bucket_len = ceil(static_cast<double>(M - m) / static_cast<double>(nums.size() - 1));
    vector<pair<int, int> > bucket_v(nums.size(), make_pair(INT_MAX, INT_MIN));
    for(auto & num : nums) {
      auto indx = (num - m) / bucket_len;
      if(bucket_v[indx].first != INT_MAX) {
        bucket_v[indx].first = min(bucket_v[indx].first, num);
        bucket_v[indx].second = max(bucket_v[indx].second, num);
      } else {
        bucket_v[indx] = make_pair(num, num);
      }
    }
    size_t i = 0;
    while(bucket_v[i].first == INT_MAX) i ++;
    size_t j = i + 1;
    while(bucket_v[j].first == INT_MAX) j ++;
    while(j < bucket_v.size()) {
      result = max(result, bucket_v[j].first - bucket_v[i].second);
      i = j;
      j ++;
      while(bucket_v[j].first == INT_MAX) j ++;
    }
    return result;
  }
};
