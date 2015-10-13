class Solution {

 public:
  bool isStrobogrammatic(string num) {
    unordered_map<char, char> M;
    M['0'] = '0'; M['1'] = '1'; M['8'] = '8';
    M['6'] = '9'; M['9'] = '6';
    string rnum;
    for(int i = num.size() - 1; i >= 0; --i) {
      if(!M.count(num[i])) return false;
      rnum.push_back(M[num[i]]);
    }
    return rnum == num;
  }
};
