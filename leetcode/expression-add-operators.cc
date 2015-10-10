using ll = long long;
class Solution {

 public:
  void bt(int indx, string leftExp, ll val, ll prevVal, char prevOp) {
    if(indx == num.size() && val == target) {
      cout << val << endl;
      cout << target << endl;
      result.push_back(leftExp);
      return;
    }
    for(int i = indx + 1; i <= num.size(); ++i) {
      string expression = num.substr(indx, i - indx);
      ll v = stoll(expression);
      if(to_string(v).size() != expression.size()) break;
      bt(i, leftExp + '+' + expression, val + v, v, '+');
      bt(i, leftExp + '-' + expression, val - v, v, '-');
      int vv = val * v;
      if(prevOp == '+') vv = (val - prevVal) + prevVal * v;
      if(prevOp == '-') vv = (val + prevVal) - prevVal * v;
      bt(i, leftExp + '*' + expression, vv, prevVal * v, prevOp);
    }
  }

  vector<string> addOperators(string num, int target) {
    this->target = target;
    this->num = num;
    result.resize(0);
    for(int i = 1; i <= num.size(); ++i) {
      string leftExp = num.substr(0, i);
      ll curr = stoll(leftExp);
      if(to_string(curr).size() != leftExp.size()) break;
      bt(i, leftExp, curr, curr, '#');
    }
    return result;
  }

 private:
  string num;
  ll target;
  vector<string> result;
};
