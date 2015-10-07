class Solution {
 public:
  int cal(int x, int y, char ch) {
    if(ch == '+') return x + y;
    if(ch == '-') return x - y;
    if(ch == '*') return x * y;
  }

  vector<int> diffWaysToCompute(string input) {
    vector<int> sums;
    bool no_op = true;
    for(int i = 0; i < input.size(); ++i) {
      if(input[i] == '+' || input[i] == '-' || input[i] == '*') {
        no_op = false;
        vector<int> left_sums = diffWaysToCompute(input.substr(0, i));
        vector<int> right_sums = diffWaysToCompute(input.substr(i + 1, input.size() - i - 1));
        for(auto & lsum : left_sums) {
          for(auto & rsum : right_sums) {
            sums.push_back(cal(lsum, rsum, input[i]));
          }
        }
      }
    }
    if(no_op) {
      sums.push_back(stoi(input));
    }
    return sums;
  }
};
