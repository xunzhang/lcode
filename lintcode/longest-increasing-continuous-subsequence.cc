class Solution {
 public:
  int longestIncreasingContinuousSubsequence(vector<int>& A) {
    if(A.size() <= 2) return A.size();
    int lr = 2;
    int v = A[1], len = 2;
    int flag = A[0] < A[1] ? 0 : 1; // 0: increase | 1 : decrease
    for(int i = 2; i < A.size(); ++i) {
      if(flag == 0) {
        if(A[i] >= v) len += 1;
        else { len = 2; flag = 1; }
      } else {
        if(A[i] <= v) len += 1;
        else { len = 2; flag = 0; }
      }
      v = A[i];
      lr = max(lr, len);
    }
    return lr;
  }
};

