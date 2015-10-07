class Solution {
 public:
  int maxArea(vector<int>& height) {
    int s = 0, e = height.size() - 1;
    int area = 0;
    while(s < e) {
      int ht = min(height[s], height[e]);
      area = max(area, ht * (e - s));
      if(height[s] < height[e]) {
        s ++;
      } else {
        e --;
      }
    }
    return area;
  }
};
