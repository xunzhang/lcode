class Solution {
 public:
  vector<vector<int> > kSumII(vector<int> A, int k, int target) {
    vector<int> tmp;
    vector<vector<int>> result;
    foo(0, A, k, target, tmp, result);
    return result;
  }

  void foo(int indx, vector<int> & A, int k, int target, vector<int> & tmp, vector<vector<int>> & result) {
    if(indx >= A.size() || target <= 0) return;
    if(k == 1) {
      for(int i = indx; i < A.size(); ++i) {
        if(A[i] == target) {
          tmp.push_back(A[i]);
          result.push_back(tmp);
          break;
        }
      }
    } else {
      vector<int> tmp2 = tmp;
      tmp2.push_back(A[indx]);
      foo(indx + 1, A, k - 1, target - A[indx], tmp2, result);
      foo(indx + 1, A, k, target, tmp, result);
    }
  }
};


