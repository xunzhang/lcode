class Solution {
 public:
  /**
   * @param A, B: Two integer arrays.
   * @return: Their smallest difference.
   */
  int smallestDifference(vector<int> &A, vector<int> &B) {
    // write your code here
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int i = 0, j = 0;
    int diff = INT_MAX;
    while(i < A.size() && j < B.size()) {
      diff = min(diff, abs(A[i] - B[j]));
      if(A[i] > B[j]) {
        j ++;
      } else if(A[i] < B[j]) {
        i ++;
      } else return 0;
    }
    return diff;
  }
};


