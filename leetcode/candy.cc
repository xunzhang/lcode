class Solution {
 public:
  int candy(vector<int>& ratings) {
    vector<int> candies(ratings.size(), 1);
    for(int i = 0; i < ratings.size() - 1; ++i) {
      if(ratings[i] < ratings[i+1]) {
        candies[i+1] = candies[i] + 1;
      }
    }
    for(int i = ratings.size() - 1; i > 0; --i) {
      if(ratings[i-1] > ratings[i]) {
        candies[i-1] = max(candies[i-1], candies[i] + 1);
      }
    }
    int sum = 0;
    for(auto & v : candies) sum += v;
    return sum;
  }
};
