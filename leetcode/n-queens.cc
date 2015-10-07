class Solution {
 public:
  bool valid(int row, vector<int> & cols) {
    for(int i = 0; i < row; ++i) {
      if(cols[row] == cols[i] || abs(cols[row] - cols[i]) == row - i) return false;
    }
    return true;
  }

  void bt(int n, int row, vector<int> & cols, vector<vector<string> > & result) {
    if(row == n) {
      vector<string> tmp;
      for(int i = 0; i < n; ++i) {
        string ttmp(n, '.');
        ttmp[cols[i]] = 'Q';
        tmp.push_back(ttmp);
      }
      result.push_back(tmp);
      return;
    }
    for(int i = 0; i < n; ++i) {
      cols[row] = i;
      if(valid(row, cols)) {
        bt(n, row + 1, cols, result);
      }
    }
  }

  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string> > result;
    vector<int> cols(n, -1);
    bt(n, 0, cols, result);
    return result;
  }
};
