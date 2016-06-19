class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int ones = 0;
    while(n) {
      n = n & (n - 1);
      ones += 1;
    }
    return ones;
  }

  vector<int> countBits_naive(int num) {
    int start = onesTable.size();
    for(int i = start; i <= num; ++i) {
      onesTable.push_back(hammingWeight(i));
    }
    vector<int> r(onesTable);
    r.resize(num + 1);
    return r;
  }

  vector<int> countBits(int num) {
    if(num == 0) return vector<int>{0};
    vector<int> r = {0, 1};
    if(num == 1) return r;
    while(1) {
      int start = r.size();
      int width = r.size() / 2;
      for(int i = 0; i < 2 * width; ++i) {
        if(i < width) r.push_back(r[width + i]);
        else r.push_back(r[width + i] + 1);
        if(r.size() == num + 1) return r;
      }
    }
  }

 private:
  vector<int> onesTable;
};
