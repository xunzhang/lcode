class Solution {
 public:
  void bt(int start, int n, int k, vector<int> & tmp, vector<vector<int>> & result) {
    if(k == 0) {
      result.push_back(tmp);
      return;
    }
    for(int i = start; i <= n - k + 1; ++i) {
      tmp.push_back(i);
      bt(i + 1, n, k - 1, tmp, result);
      tmp.pop_back();
    }
  }

  vector<vector<int>> combine(int n, int k) {
    vector<int> tmp;
    vector<vector<int>> result;
    bt(1, n, k, tmp, result);
    return result;
  }
};
