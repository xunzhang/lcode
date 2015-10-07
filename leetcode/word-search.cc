class Solution {

 public:
  bool bt(vector<vector<char>> & board, vector<vector<int>> & visited, string word, int i, int j) {
    if(word.size() == 0) return true;
    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
    if(visited[i][j] == 1) return false;
    if(board[i][j] == word[0]) {
      visited[i][j] = 1;
      bool r = bt(board, visited, word.substr(1, word.size() - 1), i - 1, j)
          || bt(board, visited, word.substr(1, word.size() - 1), i, j - 1)
          || bt(board, visited, word.substr(1, word.size() - 1), i + 1, j)
          || bt(board, visited, word.substr(1, word.size() - 1), i, j + 1);
      if(r) return true;
      visited[i][j] = 0;
    }
    return false;
  }

  bool exist(vector<vector<char>> & board, string word) {
    vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
    for(int i = 0; i < board.size(); ++i) {
      for(int j = 0; j < board[0].size(); ++j) {
        if(board[i][j] == word[0]) {
          if(bt(board, visited, word, i, j)) return true;
        }
      }
    }
    return false;
  }
};
