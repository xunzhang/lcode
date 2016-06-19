class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> dups;
    if((nums1.size() == 0) || (nums2.size() == 0)) return dups;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    for(size_t i = 0; i < nums2.size(); ++i) {
      if(binary_search(nums1.begin(), nums1.end(), nums2[i])) {
        dups.push_back(nums2[i]);
        while(((i + 1) < nums2.size()) && nums2[i+1] == nums2[i]) ++i;
      }
    }
    return dups;
  }
};
