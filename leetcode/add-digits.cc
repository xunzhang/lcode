class Solution {
 public:
  int addDigits(int num) {
    if(num == 0) return 0;
    int v = num % 9;
    if(v == 0) return 9;
    return v;
  }
};
