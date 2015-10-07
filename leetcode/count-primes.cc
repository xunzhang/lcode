class Solution {
 public:
  // O(n) space, O(nloglogn) time
  int countPrimes(int n) {
    if(n == 0) return 0;
    vector<bool> table(n, true);
    for(int i = 2; i * i < n; i ++) {
      if(!table[i]) continue;
      for(int j = i * i; j < n; j += i) table[j] = false;
    }
    int result = 0;
    for(int i = 2; i < n; ++i) {
      if(table[i]) result += 1;
    }
    return result;
  }
};
