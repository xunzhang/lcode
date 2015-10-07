class Solution {
 public:
  void solve(vector<vector<char>>& board) {
    if(board.size() == 0) return;
    int m = board.size(), n = board[0].size();
    vector<vector<int>> alive(m, vector<int>(n, 0));
    queue<pair<int, int>> q;
    for(int i = 0; i < n; ++i) {
      if(board[0][i] == 'O') {
        alive[0][i] = 1;
        q.push(make_pair(0, i));
      }
      if(board[m-1][i] == 'O') {
        alive[m-1][i] = 1;
        q.push(make_pair(m-1, i));
      }
    }
    for(int i = 1; i < m - 1; ++i) {
      if(board[i][0] == 'O') {
        alive[i][0] = 1;
        q.push(make_pair(i, 0));
      }
      if(board[i][n-1] == 'O') {
        alive[i][n-1] = 1;
        q.push(make_pair(i, n-1));
      }
    }
    while(!q.empty()) {
      auto loc = q.front(); q.pop();
      int x = loc.first, y = loc.second;
      if(x - 1 > 0 && board[x-1][y] == 'O' && alive[x-1][y] == 0) {
        alive[x-1][y] = 1;
        q.push(make_pair(x-1, y));
      }
      if(x + 1 < m - 1 && board[x+1][y] == 'O' && alive[x+1][y] == 0) {
        alive[x+1][y] = 1;
        q.push(make_pair(x+1, y));
      }
      if(y - 1 > 0 && board[x][y-1] == 'O' && alive[x][y-1] == 0) {
        alive[x][y-1] = 1;
        q.push(make_pair(x, y-1));
      }
      if(y + 1 < n - 1 && board[x][y+1] == 'O' && alive[x][y+1] == 0) {
        alive[x][y+1] = 1;
        q.push(make_pair(x, y+1));
      }
    }
    for(int i = 0; i < m; ++i) {
      for(int j = 0; j < n; ++j) {
        if(alive[i][j] == 0 && board[i][j] == 'O') board[i][j] = 'X';
      }
    }
  }
};
