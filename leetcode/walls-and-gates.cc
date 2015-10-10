using coord = pair<int, int>;
class Solution {

 public:
  void wallsAndGates(vector<vector<int>>& rooms) {
    if(rooms.size() == 0) return;
    int m = rooms.size(), n = rooms[0].size();
    queue<pair<coord, int> > Q;
    for(int i = 0; i < m; ++i) {
      for(int j = 0; j < n; ++j) {
        if(rooms[i][j] == 0)
          Q.push(make_pair(make_pair(i, j), 0));
      }
    }
    while(!Q.empty()) {
      auto tmp = Q.front(); Q.pop();
      int x = tmp.first.first, y = tmp.first.second, dis = tmp.second;
      if(x - 1 >= 0 && dis + 1 < rooms[x-1][y]){ // rooms[x-1][y] != -1 && rooms[x-1][y] != 0) {
        rooms[x-1][y] = dis + 1;
        Q.push(make_pair(make_pair(x-1, y), dis + 1));
      }
      if(y - 1 >= 0 && dis + 1 < rooms[x][y-1]) {
        rooms[x][y-1] = dis + 1;
        Q.push(make_pair(make_pair(x, y-1), dis + 1));
      }
      if(x + 1 < m && dis + 1 < rooms[x+1][y]) {
        rooms[x+1][y] = dis + 1;
        Q.push(make_pair(make_pair(x+1, y), dis + 1));
      }
      if(y + 1 < n && dis + 1 < rooms[x][y+1]) {
        rooms[x][y+1] = dis + 1;
        Q.push(make_pair(make_pair(x, y+1), dis + 1));
      }
    }
  }
};
