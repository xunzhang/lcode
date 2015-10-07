class Solution {
 public:
  void bt(int indx,
          vector<int> & candidates,
          int target,
          vector<int> & tmp,
          vector<vector<int>> & result) {
    if(target < 0) return;
    if(target == 0) {
      result.push_back(tmp);
      return;
    }
    for(int i = indx; i < candidates.size(); ++i) {
      tmp.push_back(candidates[i]);
      bt(i + 1, candidates, target - candidates[i], tmp, result);
      tmp.pop_back();
      i ++;
      while(i < candidates.size() && candidates[i] == candidates[i-1]) i ++;
    }
  }



  vector<vector<int>> combinationSum(vector<int> & candidates,
                                     int target) {
    vector<int> tmp;
    vector<vector<int>> result;
    sort(candidates.begin(), candidates.end());
    bt(0, candidates, target, tmp, result);
    return result;
  }
};
