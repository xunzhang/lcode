class Solution {

 public:
  void gameOfLife(vector<vector<int>>& board) {
    if(board.size() == 0) return;
    int m = board.size(), n = board[0].size();
    int neighbor[8][2] = {{-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}};
    for(int i = 0; i < m; ++i) {
      for(int j = 0; j < n; ++j) {
        int lives = 0;
        for(int k = 0; k < 8; ++k) {
          int x = i + neighbor[k][0], y = j + neighbor[k][1];
          int x = i + neighbor[k][0], y = j + neighbor[k][1];
          if(x < 0 || x >= m || y < 0 || y >= n) continue;
          if(board[x][y] & 1) lives ++;
        }
        if(board[i][j] & 1) {
          if(lives == 2 || lives == 3) board[i][j] = 3;
        } else {
          if(lives == 3) board[i][j] = 2;
        }
      }
    }
    for(int i = 0; i < m; ++i) {
      for(int j = 0; j < n; ++j) {
        board[i][j] = board[i][j] >> 1;
      }
    }
  }
};
