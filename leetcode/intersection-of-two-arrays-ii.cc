class Solution {
 public:
  // follow up 3
  // time complexity: O(N)
  // space complexity: O(M), but only nums1 must be loaded into memory
  vector<int> intersect_hm(vector<int>& nums1, vector<int>& nums2) {
    vector<int> dups;
    if((nums1.size() == 0) || (nums2.size() == 0)) return dups;
    unordered_map<int, int> M;
    for(auto & v : nums1) M[v] += 1;
    for(auto & v : nums2) {
      auto it = M.find(v);
      if(it != M.end()) {
        if(it->second > 0) {
          dups.push_back(v);
          it->second -= 1;
        }
      }
    }
    return dups;
  }

  // two pointer solution
  // time complexity: O(MlogM) + O(NlogN) + O(min(M, N)), O(min(M, N)) if already sorted
  // space complexity: O(1), but nums1 and nums2 must be loaded into memory
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> dups;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int a = 0, b = 0;
    while(a < nums1.size() && b < nums2.size()) {
      if(nums1[a] < nums2[b]) {
        a ++;
      } else if(nums1[a] > nums2[b]) {
        b ++;
      } else {
        dups.push_back(nums1[a]);
        a++; b++;
      }
    }
    return dups;
  }
};
