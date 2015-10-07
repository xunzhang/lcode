class Solution {
 
 public:
  void foo(vector<vector<char>> & grid, int i, int j) {
    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;
    if(grid[i][j] == '0') return;
    grid[i][j] = '0';
    foo(grid, i - 1, j);
    foo(grid, i, j - 1);
    foo(grid, i + 1, j);
    foo(grid, i, j + 1);
  }

  int numIslands(vector<vector<char>>& grid) {
    if(grid.size() == 0) return 0;
    int count = 0;
    for(int i = 0; i < grid.size(); ++i) {
      for(int j = 0; j < grid[0].size(); ++j) {
        if(grid[i][j] == '1') {
          count ++;
          foo(grid, i, j);
        }
      }
    }
    return count;
  }
};


