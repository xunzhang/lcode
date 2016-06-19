class MedianFinder {
 public:

  // Adds a number into the data structure.
  void addNum(int num) {
    maxH.push(num); int tmp = maxH.top(); maxH.pop();
    minH.push(tmp);
    if(minH.size() > maxH.size()) {
      tmp = minH.top(); minH.pop(); maxH.push(tmp);
    }
  }

  // Returns the median of current data stream
  double findMedian() {
    if (maxH.size() == minH.size()) return (maxH.top() + minH.top()) / 2.0;
    else return maxH.top();
  }
 private:
  priority_queue<int, vector<int>, less<int>> maxH;
  priority_queue<int, vector<int>, greater<int>> minH;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
