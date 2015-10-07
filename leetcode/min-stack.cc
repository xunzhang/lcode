class MinStack {
 public:
  void push(int x) {
    stk1.push(x);
    if(stk2.empty()) { stk2.push(x); return; }
    if(x <= stk2.top()) { stk2.push(x); return; }
  }

  void pop() {
    int v = stk1.top();
    stk1.pop();
    if(v == stk2.top()) stk2.pop();
  }

  int top() { return stk1.top(); }

  int getMin() { return stk2.top(); }

 private:
  stack<int> stk1, stk2;
};
