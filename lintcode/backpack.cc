// 背包问题2价值一样的情形,即A[i] = V[i]
class Solution {

 public:
  /**
   * @param m: An integer m denotes the size of a backpack
   * @param A: Given n items with size A[i]
   * @return: The maximum size
   */
  int backPack_regid(int m, vector<int> A) {
    // write your code here
    vector<vector<int>> f(A.size(), vector<int>(m + 1, 0));
    for(int w = 0; w <= m; ++w) {
      if(w >= A[0]) f[0][w] = A[0];
    }
    for(int i = 1; i < A.size(); ++i) {
      for(int w = 0; w <= m; ++w) {
        if(w - A[i] < 0) f[i][w] = f[i-1][w];
        else f[i][w] = max(f[i-1][w], f[i-1][w-A[i]] + A[i]);
      }
    }
    return f[A.size()-1][m];
  }

  int backPack(int m, vector<int> A) {
    // write your code here
    vector<int> f(m + 1, 0);
    for(int w = 0; w <= m; ++w) {
      if(w >= A[0]) f[w] = A[0];
    }
    for(int i = 1; i < A.size(); ++i) {
      for(int w = m; w >= 0; --w) {
        if(w >= A[i]) f[w] = max(f[w], f[w-A[i]] + A[i]);
      }
    }
    return f[m];
  }
};
