class Solution {
 public:
  bool firstWillWin(vector<int> &values) {
    int N = values.size();
    if(values.size() < 3) return true;
    vector<int> sums(values.size(), 0);
    sums[0] = values[0];
    for(int i = 1; i < values.size(); ++i) sums[i] = sums[i-1] + values[i];
    vector<vector<int>> table(N, vector<int>(N, 0));
    for(int i = N - 1; i >= 0; --i) {
      for(int j = i; j < N; ++j) {
        if(i == j) table[i][j] = values[i];
        else {
          int v1 = values[i] + (sums[j] - sums[i]) - table[i+1][j];
          int v2 = values[j] + (sums[j-1] - sums[i-1]) - table[i][j-1];
          table[i][j] = max(v1, v2);
        }
      }
    }
    if((values[0] + sums.back() - table[1][N-1]) > table[1][N-1]) return true;
    if((values[N-1] + sums[N-2] - table[0][N-2]) > table[0][N-2]) return true;
    return false;
  }
};

