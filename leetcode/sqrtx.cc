class Solution {
 public:
  double mySqrt(double x) {
    double result = x / 2., s = 0., e = x;
    while(fabs(result * result - x) > 1e-6) {
      result = s + (e - s) / 2;
      if(result * result >= x) e = result;
      else s = result;
    }
    return result;
  }

  int mySqrt_newton(int x) {
    double result = 1.;
    for(int i = 0; i < 100; ++i) {
      result = (result + static_cast<double>(x) / result) / 2;
    }
    return static_cast<int>(result);
  }
};
