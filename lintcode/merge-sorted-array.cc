class Solution {
 public:
  /**
   * @param A and B: sorted integer array A and B.
   * @return: A new sorted integer array
   */
  vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
    // write your code here
    if(A.size() < B.size()) return mergeSortedArray(B, A);
    int i = A.size() - 1, j = B.size() - 1;
    for(int k = 0; k < B.size(); ++k) A.push_back(0);
    int k = A.size() - 1;
    while(i >= 0 && j >= 0) {
      if(A[i] > B[j]) A[k--] = A[i--];
      else A[k--] = B[j--];
    }
    while(j >= 0) A[k--] = B[j--];
    return A;
  }
};

