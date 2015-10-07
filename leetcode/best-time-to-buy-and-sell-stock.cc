class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int maxP = 0;
    int mmin = INT_MAX;
    for(int i = 0; i < prices.size(); ++i) {
      mmin = min(mmin, prices[i]);
      maxP = max(maxP, prices[i] - mmin);
    }
    return maxP;
  }
};
