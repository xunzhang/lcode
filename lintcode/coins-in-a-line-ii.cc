class Solution {
 public:
  bool firstWillWin(const vector<int> &values) {
    if(values.size() < 3) return true;

    vector<int> table(values.size(), 0), sums(values.size(), 0);

    sums[0] = values[0];
    for(int i = 1; i < values.size(); ++i) sums[i] += sums[i-1] + values[i];

    table[values.size()-1] = values[values.size()-1];
    table[values.size()-2] = values[values.size()-1] + values[values.size()-2];
    for(int i = values.size() - 3; i >= 0; --i) {
      int v1 = values[i] + (sums.back() - sums[i]) - table[i+1];
      int v2 = values[i] + values[i+1] + (sums.back() - sums[i+1]) - table[i+2];
      table[i] = max(v1, v2);
    }
    return table[0] > (sums.back() - table[0]);
  }
};
