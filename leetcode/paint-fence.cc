class Solution {

 public:

  // 最后两个不同色 + 最后两个同色(隐含最后第三个不同色)
  int numWays(int n, int k) {
    if(n == 0 || k == 0) return 0;
    if(k == 1) {
      if(n <= 2) return 1;
      else return 0;
    }
    vector<int> table(n);
    table[0] = k;
    table[1] = k * k;
    for(int i = 2; i < n; ++i) table[i] = (table[i-1] + table[i-2]) * (k - 1);
    return table.back();
  }
};
