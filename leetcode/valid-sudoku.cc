class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    // check rows and cols
    for(int i = 0; i < 9; ++i) {
      unordered_set<char> rowMap, colMap;
      for(int j = 0; j < 9; ++j) {
        if(board[i][j] != '.') {
          if(rowMap.count(board[i][j])) return false;
          rowMap.insert(board[i][j]);
        }
        if(board[j][i] != '.') {
          if(colMap.count(board[j][i])) return false;
          colMap.insert(board[j][i]);
        }
      }
    }

    // check sub blocks
    for(int i = 0; i < 9; i += 3) {
      for(int j = 0; j < 9; j += 3) {
        unordered_set<char> Map;
        for(int k1 = i; k1 < i + 3; ++k1) {
          for(int k2 = j; k2 < j + 3; ++k2) {
            if(board[k1][k2] != '.') {
              if(Map.count(board[k1][k2])) return false;
              Map.insert(board[k1][k2]);
            }
          }
        }
      }
    }
    return true;
  }
};
