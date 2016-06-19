class MovingAverage {
 public:
  /** Initialize your data structure here. */
  MovingAverage(int size) {
    sz = size;
  }

  double next(int val) {
    if(Q.size() < sz) {
      Q.push(val);
      sum += val;
    } else {
      int first = Q.front(); Q.pop();
      Q.push(val);
      sum = sum - first + val;
    }
    return static_cast<double>(sum) / Q.size();
  }

 private:
  int sz;
  int sum = 0;
  std::queue<int> Q;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
