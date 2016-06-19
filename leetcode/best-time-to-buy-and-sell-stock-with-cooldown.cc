class Solution {
 public:
  // buy(k): 以buy结束（上一次操作是buy），第k天的最大利润
  int maxProfit(vector<int>& prices) {
    if(prices.empty()) return 0;
    vector<int> buy(prices.size(), 0), sell(prices.size(), 0);
    buy[0] = -prices[0]; buy[1] = max(-prices[0], -prices[1]);
    sell[0] = 0; sell[1] = max(0, prices[1] - prices[0]);
    for(int i = 2; i < prices.size(); ++i) {
      buy[i] = max(buy[i-1], sell[i-2] - prices[i]);
      sell[i] = max(sell[i-1], buy[i-1] + prices[i]);
    }
    return sell.back();
  }
};
