class Solution {
 public:
  void bt(int indx, int target, vector<int> & tmp, vector<vector<int>> & result) {
    if(target < 0) return;
    if(target == 0) {
      if(tmp.size() == ks) {
        result.push_back(tmp);
      }
      return;
    }
    for(int i = indx; i < candidates.size(); ++i) {
      tmp.push_back(candidates[i]);
      bt(i + 1, target - candidates[i], tmp, result);
      tmp.pop_back();
    }
  }

  vector<vector<int>> combinationSum3(int k, int n) {
    ks = k;
    candidates = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> tmp;
    vector<vector<int>> result;
    bt(0, n, tmp, result);
    return result;
  }
 private:
  vector<int> candidates;
  int ks;
};
