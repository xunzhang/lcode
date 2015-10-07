class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    vector<int> table(triangle.size());
    for(int i = 0; i < triangle.back().size(); ++i) {
      table[i] = triangle.back()[i];
    }
    for(int row = triangle.size() - 2; row >= 0; --row) {
      for(int col = 0; col < triangle[row].size(); ++col) {
        table[col] = min(table[col], table[col+1]) + triangle[row][col];
      }
    }
    return table[0];
  }
};
