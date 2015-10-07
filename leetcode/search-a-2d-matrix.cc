class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    // find a row
    int k = -1;
    int s = 0, e = m - 1;
    while(s <= e) {
      k = s + (e - s) / 2;
      if(matrix[k].back() == target) {
        return true;
      } else if(target < matrix[k].back()) {
        e = k - 1;
      } else {
        s = k + 1;
      }
    }
    if(target > matrix[k].back()) k += 1;
    if(k == m) return false;
    // find target
    // in kth row
    s = 0, e = n - 1;
    while(s <= e) {
      int mid = s + (e - s) / 2;
      if(matrix[k][mid] == target) {
        return true;
      } else if(target < matrix[k][mid]) {
        e = mid - 1;
      } else {
        s = mid + 1;
      }
    }
    return false;
  }
};
