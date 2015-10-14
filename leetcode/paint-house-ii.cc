class Solution {

 public:
  // O(k) space, O(n*k) time
  int minCostII(vector<vector<int>>& costs) {
    if(costs.size() == 0) return 0;
    int N = costs.size(), k = costs[0].size();
    vector<int> T(k, INT_MAX);
    int small1, small2;
    for(int i = 0; i < N; ++i) {
      int small1_old = i == 0 ? 0 : small1;
      int small2_old = i == 0 ? 0 : small2;
      small1 = INT_MAX;
      small2 = INT_MAX;
      for(int j = 0; j < k; ++j) {
        // update T[j]
        if(T[j] == small1_old) {
          T[j] = costs[i][j] + small2_old;
        } else {
          T[j] = costs[i][j] + small1_old;
        }
        // update small1, small2
        if(T[j] >= small1) {
            small2 = min(T[j], small2);
        } else {
          small2 = small1;
          small1 = T[j];
        }
      }
    }
    return small1;
  }
};
