class Solution {

 public:
  int minCost(vector<vector<int>>& costs) {
    if(costs.size() == 0) return 0;
    vector<vector<int> > costTable = costs;
    for(int i = 1; i < costs.size(); ++i) {
      costTable[i][0] = min(costTable[i-1][1], costTable[i-1][2]) + costs[i][0];
      costTable[i][1] = min(costTable[i-1][0], costTable[i-1][2]) + costs[i][1];
      costTable[i][2] = min(costTable[i-1][0], costTable[i-1][1]) + costs[i][2];
    }
    return min(costTable.back()[0], min(costTable.back()[1], costTable.back()[2]));
  }
};
