// https://leetcode.com/problems/two-sum-iii-data-structure-design/
class TwoSum {
 public:
  // O(1)
  void add(int number) {
    D[number] += 1;
  }
  // O(D.size())
  bool find(int value) {
    for(auto & kv : D) {
      int v = value - kv.first;
      if(D.count(v)) {
        if(kv.first == v) {
          if(D[v] > 1) {
            return true;
          }
        } else {
          return true;
        }
      }
    }
    return false;
  }
 private:
  unordered_map<int, int> D;
};
