class Solution {
 public:
  /**
   *@param A: A positive integer which has N digits, A is a string.
   *@param k: Remove k digits.
   *@return: A string
   */
  string DeleteDigits(string A, int k) {
    // wirte your code here
    string s;
    if (k >= A.size()) return s;
    int cnt = 0;
    for (int i = 0; i < A.size(); ++i) {
      while (!s.empty() && s.back() > A[i] && cnt < k) {
        s.pop_back();
        ++cnt;
      }
      if (A[i] != '0' || !s.empty()) { cout << i << endl; s.push_back(A[i]); }
    }
    if (cnt < k) s.resize(s.size() - k + cnt);
    return s;
  }
};
