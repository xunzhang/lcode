class Solution {
 public:
  /**
   * @param matrix, a list of lists of integers
   * @param target, an integer
   * @return a boolean, indicate whether matrix contains
   * target
   */
  bool searchMatrix(vector<vector<int> > &matrix, int target) {
    // write your code here
    if(matrix.size() == 0) return false;
    int m = matrix.size(), n = matrix[0].size();
    int s = 0, e = m - 1, mid;
    while(s <= e) {
      mid = s + (e - s) / 2;
      if(target < matrix[mid][0]) {
        e = mid - 1;
      } else if(target > matrix[mid][0]) {
        if(mid == m - 1) break;
        if(target >= matrix[mid+1][0]) s = mid + 1;
        else break;
      } else return true;
    }
    int midRow;
    s = 0, e = n - 1;
    while(s <= e) {
      midRow = s + (e - s) / 2;
      if(target < matrix[mid][midRow]) {
        e = midRow - 1;
      } else if(target > matrix[mid][midRow]) {
        s = midRow + 1;
      } else return true;
    }
    return false;
  }
};


