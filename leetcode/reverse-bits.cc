class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t result = n & 1;
    for(int i = 1; i <= 31; ++i) {
      n >>= 1;
      result <<= 1;
      result = result | (n & 1);
    }
    return result;
  }
};
