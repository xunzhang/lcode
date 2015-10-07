class Solution {
 public:
  int myAtoi(string str) {
    int result = 0;
    int indx = 0;
    bool negative = false;
    while(str[indx] == ' ') indx++;
    if(str[indx] == '-' || str[indx] == '+') { 
      if(str[indx] == '-') negative = true;
      indx ++;
    }
    if(!(str[indx] >= '0' && str[indx] <= '9')) return 0;
    while(str[indx] >= '0' && str[indx] <= '9' && indx < str.size()) {
      uint64_t v = static_cast<uint64_t>(result) * 10 + str[indx] - '0';
      if(v > INT_MAX) {
        return nagative ? INT_MIN : INT_MAX; 
      }
      result = static_cast<int>(v);
      indx += 1;
    }
    return negative ? -result : result;
  }
};
