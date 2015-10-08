class Solution {

 public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    if(dungeon.size() == 0) return 0;
    int m = dungeon.size(), n = dungeon[0].size();
    vector<vector<int>> hp(m + 1, vector<int>(n + 1, INT_MAX));
    hp[m][n-1] = 1; hp[m-1][n] = 1;
    for(int i = m - 1; i >= 0; --i) {
      for(int j = n - 1; j >= 0; --j) {
        int delta = min(hp[i+1][j], hp[i][j+1]) - dungeon[i][j];
        hp[i][j] = delta <= 0 ? 1 : delta;
      }
    }
    return hp[0][0];
  }
};
