class Solution {
 public:
  Solution() {
    D['2'] = "abc"; D['3'] = "def";
    D['4'] = "ghi"; D['5'] = "jkl"; D['6'] = "mno";
    D['7'] = "pqrs"; D['8'] = "tuv"; D['9'] = "wxyz";
    D['0'] = " ";
  }

  void bt(string digits, int indx, string & tmp, vector<string> & result) {
    if(indx == digits.size()) { 
      if(tmp != "") result.push_back(tmp);
      return;
    }
    if(digits[indx] == '1') bt(digits, indx+1, tmp, result);
    for(auto & c : D[digits[indx]]) {
      tmp += c;
      bt(digits, indx + 1, tmp, result);
      tmp.pop_back();
    }
  }
  
  vector<string> letterCombinations(string digits) {
    vector<string> result;
    string tmp;
    bt(digits, 0, tmp, result);
    return result;
  }

 private:
  unordered_map<char, string> D;
};
