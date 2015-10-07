class Solution {
 public:
  int cal(int a, int b, char op) {
    if(op == '-') return a - b;
    return a + b;
  }
  int calculate(string s) {
    stack<int> num_stk;
    stack<char> op_stk;
    for(size_t i = 0; i < s.size();) {
      if(isdigit(s[i])) {
        string tmp;
        while(isdigit(s[i])) {
          tmp += s[i];
          i += 1;
        }
        num_stk.push(stoi(tmp));
      } else if(s[i] == '+' || s[i] == '-') {
        op_stk.push(s[i]);
        i += 1;
      } else if(s[i] == '*') {
        int v = num_stk.top();
        num_stk.pop();
        while(!isdigit(s[i])) ++i;
        string tmp;
        while(isdigit(s[i])) {
          tmp += s[i];
          i += 1;
        }
        num_stk.push(v * stoi(tmp));
      } else if(s[i] == '/') {
        int v = num_stk.top();
        num_stk.pop();
        while(!isdigit(s[i])) ++i;
        string tmp;
        while(isdigit(s[i])) {
          tmp += s[i];
          i += 1;
        }
        num_stk.push(v / stoi(tmp));
      } else {
        // space
        i += 1;
      }
    }
    stack<int> num_stk2;
    stack<char> op_stk2;
    while(!num_stk.empty()) {
      num_stk2.push(num_stk.top());
      num_stk.pop();
    }
    while(!op_stk.empty()) {
      op_stk2.push(op_stk.top());
      op_stk.pop();
    }
    int value = num_stk2.top();
    num_stk2.pop();
    while(!op_stk2.empty()) {
      int r = num_stk2.top();
      num_stk2.pop();
      value = cal(value, r, op_stk2.top());
      op_stk2.pop();
    }
    return value;
  }
};
