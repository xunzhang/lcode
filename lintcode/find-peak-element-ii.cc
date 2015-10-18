class Solution {
 public:
  /**
   * @param A: An integer matrix
   * @return: The index of the peak
   */
  // O(nlogn)
  vector<int> findPeakII(vector<vector<int> > A) {
    // write your code here
    int m = A.size(), n = A[0].size();
    int s = 0, e = n - 1;
    while(s <= e) {
      int mid = s + (e - s) / 2;
      int mx = INT_MIN, j = 0;
      for(int i = 0; i < m; ++i) {
        if(A[i][mid] > mx) {
          mx = max(mx, A[i][mid]);
          j = i;
        }
      }
      if(A[j][mid] > A[j][mid+1] && A[j][mid] > A[j][mid-1]) return {j, mid};
      else if(A[j][mid] < A[j][mid+1]) {
        s = mid + 1;
      } else {
        e = mid - 1;
      }
    }
  }
};


