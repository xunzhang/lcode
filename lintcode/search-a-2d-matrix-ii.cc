class Solution {
 public:
  /**
   * @param matrix: A list of lists of integers
   * @param target: An integer you want to search in matrix
   * @return: An integer indicate the total occurrence of
   * target in the given matrix
   */
  int searchMatrix(vector<vector<int> > &matrix, int target) {
    // write your code here
    if(matrix.size() == 0) return 0;
    int m = matrix.size(), n = matrix[0].size();
    int row = 0, col = n - 1;
    int cnt = 0;
    while(row < m && col >= 0) {
      if(target < matrix[row][col]) {
        col -= 1;
      } else if(target > matrix[row][col]) {
        row += 1;
      } else {
        cnt ++;
        col -= 1;
      }
    }
    return cnt;
  }
};


