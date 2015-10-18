class Solution {
 public:
  /** 
   *@param L: Given n pieces of wood with length L[i]
   *@param k: An integer
   *return: The maximum length of the small pieces.
   */
  int woodCut(vector<int> L, int k) {
    // write your code here
    int Len = 0;
    for(auto & v : L) Len = max(Len, v);
    int s = 1, e = Len;
    int m;
    while(s <= e) {
      m = s + (e - s) / 2;
      if(cutoff(L, k, m)) {
        if(!cutoff(L, k, m+1)) return m;
        s = m + 1;
      } else {
        e = m - 1;
      }
    }
    return 0;
  }

 private:
  bool cutoff(vector<int> & A, int k, int l) {
    int piece = 0;
    for(auto & v : A) piece += v / l;
    return piece >= k;
  }
};
