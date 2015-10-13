class Solution {

 public:
  vector<string> foo(int n) {
    if(n == 1) return {"0", "1", "8"};
    if(n == 2) return {"00", "11", "69", "88", "96"};
    auto beforeResult = foo(n - 2);
    vector<string> result;
    for(auto & r : beforeResult) result.push_back('0' + r + '0');
    for(auto & r : beforeResult) result.push_back('1' + r + '1');
    for(auto & r : beforeResult) result.push_back('6' + r + '9');
    for(auto & r : beforeResult) result.push_back('8' + r + '8');
    for(auto & r : beforeResult) result.push_back('9' + r + '6');
    return result;
  }

  vector<string> findStrobogrammatic(int n) {
    if(n == 1) return {"0", "1", "8"};
    auto r = foo(n);
    vector<string> result;
    for(auto & v : r) {
      if(v[0] != '0') {
        result.push_back(v);
      }
    }
    return result;
  }
};
