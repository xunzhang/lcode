class Solution {

 public:
  Solution() {
    M['0'] = '0'; M['1'] = '1';
    M['6'] = '9'; M['8'] = '8'; M['9'] = '6';
  }

  bool less(string& s, string& t) {
    int m = s.length(), n = t.length(), i;
    if (m != n) return m < n; 
    for (i = 0; i < m; i++) {
      if (s[i] == t[i]) continue;
      else break;
    }
    return i == m || s[i] < t[i];
  }

  void foo(string tmp, int l, int h) {
    if(l > h) {
      if((tmp[0] != '0' || tmp.size() == 1) && less(lb, tmp) && less(tmp, hb)) cnt ++;
      return;
    }
    for(auto & kv : M) {
      tmp[l] = kv.first;
      tmp[h] = kv.second;
      if((l == h && kv.first == kv.second) || l != h) foo(tmp, l + 1, h - 1);
    }
  }

  int strobogrammaticInRange(string low, string high) {
    lb = low; hb = high; cnt = 0;
    for(int i = lb.size(); i <= hb.size(); ++i) {
      string tmp(i, ' ');
      foo(tmp, 0, i - 1);
    }
    return cnt;
  }

 private:
  int cnt;
  string lb, hb;
  unordered_map<char, char> M;
};
