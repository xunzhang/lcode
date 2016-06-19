/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
 public:
  int depthSum(vector<NestedInteger>& nestedList) {
    int sum = 0;
    foo(nestedList, 1, sum);
    return sum;
  }

 private:
  void foo(vector<NestedInteger>& nestedList, int wgt, int & sum) {
    if(nestedList.size() == 0) return;
    if(nestedList[0].isInteger()) {
      sum += wgt * nestedList[0].getInteger();
    } else {
      foo(nestedList[0].getList(), wgt + 1, sum);
    }
    if(nestedList.size() > 1) {
      vector<NestedInteger> rList(nestedList.begin() + 1, nestedList.end());
      foo(rList, wgt, sum);
    }
  }
};
