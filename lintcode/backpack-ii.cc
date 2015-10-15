class Solution {
 public:
  /**
   * @param m: An integer m denotes the size of a backpack
   * @param A & V: Given n items with size A[i] and value V[i]
   * @return: The maximum value
   */
  int backPackII_rigid(int m, vector<int> A, vector<int> V) {
    // write your code here
    vector<vector<int>> f(A.size(), vector<int>(m + 1, 0));
    for(int w = 0; w <= m; ++w) {
      if(w >= A[0]) f[0][w] = V[0];
    }
    for(int i = 1; i < A.size(); ++i) {
      for(int w = 0; w <= m; ++w) {
        if(w - A[i] < 0)
          f[i][w] = f[i-1][w];
        else
          f[i][w] = max(f[i-1][w], f[i-1][w-A[i]] + V[i]);
      }
    }
    return f[A.size()-1][m];
  }

  int backPackII(int m, vector<int> A, vector<int> V) {
    // write your code here
    vector<int> f(m + 1, 0);
    for(int w = 0; w <= m; ++w) {
      if(w >= A[0]) f[w] = V[0];
    }
    for(int i = 1; i < A.size(); ++i) {
      for(int w = m; w >= 0; --w) {
        if(w >= A[i]) f[w] = max(f[w], f[w-A[i]] + V[i]);
      }
    }
    return f[m];
  }
};
