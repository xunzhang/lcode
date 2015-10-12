class Solution {

 public:
  void bt(int n, vector<int> & tmp, vector<vector<int>> & result) {
    int start = tmp.empty() ? 2 : tmp.back();
    for(int i = start; i * i <= n; ++i) {
      if(n % i == 0) {
        tmp.push_back(i);
        tmp.push_back(n / i);
        result.push_back(tmp);
        tmp.pop_back();
        bt(n / i, tmp, result);
        tmp.pop_back();
      }
    }
  } 

  vector<vector<int>> getFactors(int n) {
    vector<vector<int>> result;
    vector<int> tmp;
    bt(n, tmp, result);
    return result;
  }
};
