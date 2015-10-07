class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> stk;
    for(size_t i = 0; i < tokens.size(); ++i) {
      if(tokens[i] == "+") {
        int r = stk.top(); stk.pop();
        int l = stk.top(); stk.pop();
        stk.push(l + r);
        continue;
      }
      if(tokens[i] == "-") {
        int r = stk.top(); stk.pop();
        int l = stk.top(); stk.pop();
        stk.push(l - r);
        continue;                
      }
      if(tokens[i] == "*") {
        int r = stk.top(); stk.pop();
        int l = stk.top(); stk.pop();
        stk.push(l * r);
        continue;                
      }
      if(tokens[i] == "/") {
        int r = stk.top(); stk.pop();
        int l = stk.top(); stk.pop();
        stk.push(l / r);
        continue;               
      }
      stk.push(stoi(tokens[i]));
    }
    return stk.top();
  }
};
