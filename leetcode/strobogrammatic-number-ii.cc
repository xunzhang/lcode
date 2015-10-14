class Solution {

 public:
  vector<string> foo(int n) {
    if(n == 1) return {"0", "1", "8"};
    if(n == 2) return {"00", "11", "69", "88", "96"};
    auto beforeResult = foo(n - 2);
    vector<string> result;
    if(n != N) for(auto & r : beforeResult) result.push_back('0' + r + '0');
    for(auto & r : beforeResult) result.push_back('1' + r + '1');
    for(auto & r : beforeResult) result.push_back('6' + r + '9');
    for(auto & r : beforeResult) result.push_back('8' + r + '8');
    for(auto & r : beforeResult) result.push_back('9' + r + '6');
    return result;
  }

  vector<string> findStrobogrammatic(int n) {
    if(n == 1) return {"0", "1", "8"};
    if(n == 2) return {"11", "69", "88", "96"};
    N = n;
    return foo(n);
  }

 private:
  int N;

// solution which could be extended in strobogrammatic-number-iii
 public:
  Solution() {
    M['0'] = '0'; M['1'] = '1';
    M['6'] = '9'; M['8'] = '8'; M['9'] = '6';
  }

  void foo(string tmp, int l, int h) {
    if(l > h) {
      if((tmp[0] != '0' || tmp.size() == 1)) rr.push_back(tmp);
      return;
    }
    for(auto & kv : M) {
      tmp[l] = kv.first;
      tmp[h] = kv.second;
      if((l == h && kv.first == kv.second) || l != h) foo(tmp, l + 1, h - 1);
    }
  }

  vector<string> findStrobogrammatic(int n) {
    string tmp(n, ' ');
    foo(tmp, 0, n - 1);
    return rr;
  }

 private:
  unordered_map<char, char> M;
  vector<string> rr;
};
