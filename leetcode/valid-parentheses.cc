class Solution {
 public:
  bool isValid(string s) {
    stack<char> stk;
    for(auto & c : s) {
      if(c == '(' || c == '[' || c == '{') stk.push(c);
      if(c == ')') {
        if(stk.empty()) return false;
        if(stk.top() != '(') return false;
        stk.pop();
      }
      if(c == ']') {
        if(stk.empty()) return false;
        if(stk.top() != '[') return false;
        stk.pop();
      }
      if(c == '}') {
        if(stk.empty()) return false;
        if(stk.top() != '{') return false;
        stk.pop();
      }
    }
    return stk.empty();
  }
};
