class Solution {
 public:
  int numTrees(int n) {
    vector<int> f(n + 1, 0);
    f[0] = 1; f[1] = 1;
    for(int k = 2; k <= n; ++k) {
      for(int i = 0; i < k; ++i) {
        f[k] += f[i] * f[k-1-i];
      }
    }
    return f[n];
  }
};
