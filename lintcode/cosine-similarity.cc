class Solution {
 public:
  /**
   * @param A: An integer array.
   * @param B: An integer array.
   * @return: Cosine similarity.
   */
  double cosineSimilarity(vector<int> A, vector<int> B) {
    // write your code here
    int result = 0, sum1 = 0, sum2 = 0;
    for(int i = 0; i < A.size(); ++i) {
      result += A[i] * B[i];
      sum1 += A[i] * A[i];
      sum2 += B[i] * B[i];
    }
    if(sum1 == 0 || sum2 == 0) return 2.0;
    double tmp = sqrt(static_cast<double>(sum1)) * sqrt(static_cast<double>(sum2));
    return static_cast<double>(result) / tmp;
  }
};
