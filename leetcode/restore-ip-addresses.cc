class Solution {
 public:
  bool valid(string s) {
    if(s.size() < 1 || s.size() > 3) return false;
    if(s[0] == '0' && s.size() != 1) return false;
    int is = stoi(s);
    if(is < 0 || is > 255) return false;
    return true;
  }

  void bt(string s, int len, string & tmp, vector<string> & result) {
    if(len == 1) {
      if(valid(s)) {
        tmp += s;
        result.push_back(tmp);
        return;
      }
      return;
    }
    for(int i = 0; i < 3 && i + 1 < s.size(); ++i) {
      string ip = s.substr(0, i+1);
      if(valid(ip)) {
        string str = tmp + ip + ".";
        bt(s.substr(i+1, s.size()-i-1), len - 1, str, result);
      }
    }
  }

  vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    string tmp;
    bt(s, 4, tmp, result);
    return result;
  }
};
