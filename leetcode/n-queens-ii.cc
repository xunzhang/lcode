class Solution {
 public:
  bool valid(int row, vector<int> & cols) {
    for(int i = 0; i < row; ++i) {
      if(cols[row] == cols[i] || abs(cols[row] - cols[i]) == row - i) return false;
    }
    return true;
  }

  void bt(int n, int row, vector<int> & cols, int & cnt) {
    if(row == n) {
      cnt += 1;
      return;
    }
    for(int i = 0; i < n; ++i) {
      cols[row] = i;
      if(valid(row, cols)) {
        bt(n, row + 1, cols, cnt);
      }
    }
  }

  int totalNQueens(int n) {
    int cnt = 0;
    vector<int> cols(n, -1);
    bt(n, 0, cols, cnt);
    return cnt;
  }
};
