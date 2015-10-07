class Solution {
 public:
  int cal(int a, int b, char op) {
    if(op == '-') return a - b;
    return a + b;
  }
  int calculate(string s) {
    stack<int> num_stk;
    stack<char> op_stk;
    int value = 0;
    char op = '+';
    for(size_t i = 0; i < s.size(); ++i) {
      if(isdigit(s[i])) {
        string tmp;
        while(isdigit(s[i])) {
          tmp += s[i];
          i += 1;
        }
        i -= 1;
        value = cal(value, stoi(tmp), op);
      } else if(s[i] == '+' || s[i] == '-') {
        op = s[i];

      } else if(s[i] == '(') {
        num_stk.push(value);
        op_stk.push(op);
        value = 0;
        op = '+';
      } else if(s[i] == ')') {
        op = op_stk.top();
        op_stk.pop();
        value = cal(num_stk.top(), value, op);
        num_stk.pop();
      } else {
        // bad input case
      }
    }
    return value;
  }

};
