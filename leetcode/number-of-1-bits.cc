class Solution {
 public:
  int hammingWeight_original(uint32_t n) {
    int result = 0;
    for(int i = 0; i < 32; ++i) {
      result += (n >> i) & 1;
    }
    return result;
  }

  int hammingWeight(uint32_t n) {
    int result = 0;
    while(n) {
      n &= (n - 1);
      result ++;
    }
    return result;
  }
};
