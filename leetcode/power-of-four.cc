class Solution {
 public:
  bool isPowerOfFour_loop(int num) {
    if(num == 0) return false;
    while(num % 4 == 0) {
      num /= 4;
    }
    return num == 1;
  }
  bool isPowerOfFour_naive(int num) {
    if(num == 0) return false;
    int offset = 0;
    int n = num;
    while((n & 1) == 0) {
      offset += 1;
      n >>= 1;
    }
    cout << offset << endl;
    return ((num & (num - 1)) == 0) && (offset % 2 == 0);
  }

  bool isPowerOfFour(int num) {
    if(num == 0) return false;
    return ((num & (num - 1)) == 0) && ((num & 0x55555555) == num);
  }
};
