class Solution {
 public:
  string simplifyPath(string path) {
    string result = "/";
    stack<string> stk, stk2;
    for(size_t i = 0; i < path.size(); ++i) {
      string tmp;
      while(i < path.size() && path[i] != '/') {
        tmp += path[i];
        i ++;
      }
      if(tmp.size() == 0 || tmp == ".") {
        continue;
      } else if(tmp == "..") { 
          if(!stk.empty()) stk.pop();
          continue;
      } else {
          stk.push(tmp);
      }
    }
    while(!stk.empty()) {
      stk2.push(stk.top());
      stk.pop();
    }
    while(!stk2.empty()) {
      result += stk2.top() + "/";
      stk2.pop();
    }
    if(result.size() == 1) return result;
    return result.substr(0, result.size() - 1);
  }
};
