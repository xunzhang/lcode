class Solution {
 public:
  int foo(int k, int num) {
    int r = 0;
    while(num) {
      if(num % 10 == k) r ++;
      num /= 10;
    }
    return r;
  }

  /*
   * param k : As description.
   * param n : As description.
   * return: How many k's between 0 and n.
   */
  int digitCounts_original(int k, int n) {
    // write your code here
    int r = 0;
    for(int i = 0; i <= n; ++i) {
      r += foo(k, i);
    }
    return r;
  }

  /*
   * param k : As description.
   * param n : As description.
   * return: How many k's between 0 and n.
   */
  int digitCounts(int k, int n) {
    // write your code here
    int r = 0;
    for(long m = 1; m <= n; m *= 10) {
      long a = n / m, b = n % m;
      r += (a + 9 - k) / 10 * m;
      if(a % 10 == k) r += b + 1;
    }
    return r;
  }
};
