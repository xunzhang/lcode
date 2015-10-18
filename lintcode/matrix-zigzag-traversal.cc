class Solution {
 public:
  /**
   * @param matrix: a matrix of integers
   * @return: a vector of integers
   */
  vector<int> printZMatrix(vector<vector<int> > &matrix) {
    // write your code here
    vector<int> result;
    if(matrix.size() == 0) return result;
    int m = matrix.size(), n = matrix[0].size();
    for(int i = 0; result.size() < m * n; ++i) {
      if(i % 2 == 0) {
        for(int k = i; k >= 0; --k) {
          if(k < m && i - k < n) result.push_back(matrix[k][i-k]);
        }
      } else {
        for(int k = 0; k <= i; ++k) {
          if(k < m && i - k < n) result.push_back(matrix[k][i-k]);
        }
        break;
      }
    }
    return result;
  }
};
