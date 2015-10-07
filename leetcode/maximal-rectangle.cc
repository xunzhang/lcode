class Solution {
 public:
  int largestRectangleArea(vector<int>& height) {
    stack<int> stk;
    height.push_back(0);
    int area = 0;
    for(int i = 0; i < height.size();) {
      if(stk.empty() || height[i] >= height[stk.top()]) {
        stk.push(i); i++;
      } else {
        int k = stk.top(); stk.pop();
        area = max(area, height[k] * (stk.empty() ? i : i - stk.top() - 1));
      }
    }
    height.pop_back();
    return area;
  }

  int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.size() == 0) return 0;
    int m = matrix.size(), n = matrix[0].size();
    int area = 0;
    for(int col = 0; col < n; ++ col) {
      vector<int> height(m, 0);
      for(int row = 0; row < m; ++row) {
        int j = col;
        while(matrix[row][j] == '1') j ++;
        height[row] = j - col;
      }
      area = max(area, largestRectangleArea(height));
    }
    return area;
  }
};
