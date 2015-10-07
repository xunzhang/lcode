class Solution {
 public:
  bool valid(vector<vector<char>> & board, int i, int j) {
    for(int k = 0; k < 9; ++k) {
      if(k != j && board[i][k] == board[i][j]) return false;
      if(k != i && board[k][j] == board[i][j]) return false;
    }
    int startx = (i / 3) * 3, starty = (j / 3) * 3;
    for(int k1 = startx; k1 < startx + 3; ++k1) {
      for(int k2 = starty; k2 < starty + 3; ++k2) {
        if(!(k1 == i && k2 == j) && board[k1][k2] == board[i][j]) return false;
      }
    }
    return true;
  }

  bool bt(vector<vector<char>> & board, int i, int j) {
    if(j >= 9) return bt(board, i + 1, 0);
    if(i == 9) return true;
    if(board[i][j] == '.') {
      for(int k = 1; k <= 9; ++k) {
        board[i][j] = '0' + k;
        if(valid(board, i, j)) {
          if(bt(board, i, j + 1)) return true;
        }
        board[i][j] = '.';
      }
    } else {
      return bt(board, i, j + 1);
    }
    return false;
  }

  void solveSudoku(vector<vector<char>>& board) {
    bt(board, 0, 0);
  }
};
