class Solution {
 public:
  int trap(vector<int>& height) {
    if(height.size() == 0) return 0;
    vector<int> lmax(height);
    int tmp = height[0];
    for(int i = 1; i < height.size(); ++i) {
      lmax[i] = tmp;
      tmp = max(height[i], tmp);
    }
    int water = 0, rmax;
    tmp = height.back();
    for(int i = height.size() - 2; i > 0; --i) {
      rmax = tmp;
      if(min(lmax[i], rmax) > height[i]) {
          water += min(lmax[i], rmax) - height[i];
      }
      tmp = max(height[i], tmp);
    }
    return water;
  }
};
