class Solution {
 public:
  string multiply(string num1, string num2) {
    if(num1 == "0" || num2 == "0") return "0";
    std::vector<int> res(num1.size() + num2.size(), 0);
    for(int i = 0; i < num1.size(); ++i) {
      for(int j = 0; j < num2.size(); ++j) {
        res[i+j+1] = res[i+j+1] + (num1[i] - '0') * (num2[j] - '0');
      }
    }
    int carry = 0;
    for(int i = res.size() - 1; i >= 0; --i) {
      int v = res[i] + carry;
      res[i] = v % 10;
      carry = v / 10;
    }
    string result;
    if(res[0] != 0) result += res[0] + '0';
    for(size_t i = 1; i < res.size(); ++i) {
      result += res[i] + '0';
    }
    return result;
  }
};
