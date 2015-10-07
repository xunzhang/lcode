class Solution {
 public:
  string addBinary(string a, string b) {
    if(a.size() < b.size()) return addBinary(b, a);
    string result;
    int carry = 0;
    for(size_t i = 0; i < b.size(); ++i) {
      int v = a[a.size()-1-i] - '0' + b[b.size()-1-i] - '0' + carry;
      result.push_back(v % 2 + '0');
      carry = v / 2;
    }
    int indx = a.size() - b.size() - 1;
    while(indx >= 0) {
      int v = a[indx] - '0' + carry;
      result.push_back(v % 2 + '0');
      carry = v / 2;
      indx -= 1;
    }
    if(carry != 0) result.push_back('1');
    reverse(result.begin(), result.end());
    return result;
  }
};
