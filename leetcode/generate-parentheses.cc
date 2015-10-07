class Solution {
 public:
  void bt(int n, int lcnt, int rcnt, string & tmp, vector<string> & result) {
    if(lcnt < rcnt || lcnt > n) return;
    if(lcnt == rcnt) {
      if(lcnt == n) {
        result.push_back(tmp);
        return;
      } else {
        tmp += "(";
        bt(n, lcnt + 1, rcnt, tmp, result);
      }
    } else {
      string s1 = tmp + ")", s2 = tmp + "(";
      // lcnt > rcnt
      bt(n, lcnt, rcnt + 1, s1, result);
      bt(n, lcnt + 1, rcnt, s2, result);
    }
  }

  vector<string> generateParenthesis(int n) {
    vector<string> result;
    string tmp;
    bt(n, 0, 0, tmp, result);
    return result;
  }
};
