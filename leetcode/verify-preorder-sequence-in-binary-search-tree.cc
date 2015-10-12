class Solution {

 public:
  // O(n) space, O(n) time
  bool verifyPreorder(vector<int>& preorder) {
    stack<int> stk;
    int lowBnd = INT_MIN;
    for(auto & v : preorder) {
      if(v < lowBnd) return false;
      while(!stk.empty() && v > stk.top()) { lowBnd = stk.top(); stk.pop(); }
      stk.push(v);
    }
    return true;
  }
};
