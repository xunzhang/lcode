class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if(prices.size() == 0) return 0;

    vector<int> startMax(prices.size(), 0), endMax(prices.size(), 0);
    int mmax = prices.back(), mmin = prices[0];
    
    for(int i = prices.size() - 2; i >= 0; --i) {
      mmax = max(mmax, prices[i]);
      startMax[i] = max(startMax[i+1], mmax - prices[i]);
    }
    for(int i = 1; i < prices.size(); ++i) {
      mmin = min(mmin, prices[i]);
      endMax[i] = max(endMax[i-1], prices[i] - mmin);
    }
    
    int maxP = 0;
    for(int i = 0; i < prices.size(); ++i) {
      maxP = max(maxP, startMax[i] + endMax[i]);
    }
    
    return maxP;
  }
};
