class Solution {
 public:
  int maxProfit(int k, vector<int>& prices) {
    if(prices.size() == 0) return 0;
    if(k > prices.size() / 2) {
      int maxP = 0;
      for(int i = 0; i < prices.size() - 1; ++i) {
        maxP += max(prices[i+1] - prices[i], 0);
      }
      return maxP;
    }
    vector<vector<int>> global(prices.size(), vector<int>(k + 1, 0)), local(prices.size(), vector<int>(k + 1, 0));
    for(int i = 1; i < prices.size(); ++i) {
      int delta = prices[i] - prices[i-1];
      for(int j = 1; j <= k; ++j) {
        local[i][j] = max(global[i-1][j-1] + max(delta, 0), local[i-1][j] + delta);
        global[i][j] = max(global[i-1][j], local[i][j]);
      }
    }
    return global[prices.size()-1][k];
  }
};
