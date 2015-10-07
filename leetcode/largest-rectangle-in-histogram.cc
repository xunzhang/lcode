class Solution {
 public:
  int largestRectangleArea(vector<int>& height) {
    stack<int> stk;
    height.push_back(0);
    int area = 0;
    for(int i = 0; i < height.size();) {
      if(stk.empty() || height[i] >= height[stk.top()]) {
        stk.push(i);
        i++;
      } else {
        int k = stk.top(); stk.pop();
        area = max(area, height[k] * (stk.empty() ? i : i - stk.top() - 1));
      }
    }
    height.pop_back();
    return area;
  }
};
