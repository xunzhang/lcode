class Solution {

 public:
  Solution() {
    table.push_back(0);
  }

  int numSquares2(int n) {
    table[0] = 0;
    for(int k = 1; k <= n; ++k) {
      for(int j = 1; j * j <= k; ++j) {
        table[k] = min(table[k], table[k-j*j] + 1);
      }
    }
    return table[n];
  }

  int numSquares(int n) {
    while(table.size() <= n) {
      int r = INT_MAX;
      for(int j = 1; j * j <= table.size(); ++j) {
        r = min(r, table[table.size()-j*j] + 1);
      }
      table.push_back(r);
    }
    return table.back();
  }

 private:
  vector<int> table;
};
