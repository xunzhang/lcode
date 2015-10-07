class Solution {

 public:
  int nthUglyNumber(int n) {
    int t2 = 0, t3 = 0, t5 = 0;
    vector<int> ugly(n);
    ugly[0] = 1;
    for(int i = 1; i < n; ++i) {
      ugly[i] = min(ugly[t2] * 2, min(ugly[t3] * 3, ugly[t5] * 5));
      if(ugly[i] == ugly[t2] * 2) t2 ++;
      if(ugly[i] == ugly[t3] * 3) t3 ++;
      if(ugly[i] == ugly[t5] * 5) t5 ++;
    }
    return ugly[n-1];
  }
};
