class Solution {
 public:
  Solution() {
    table['I'] = 1;
    table['V'] = 5;
    table['X'] = 10;
    table['L'] = 50;
    table['C'] = 100;
    table['D'] = 500;
    table['M'] = 1000;
  }
  int romanToInt(string s) {
    if(s.size() == 1) return table[s[0]];
    int result = 0;
    for(size_t i = 0; i < s.size() - 1; ++i) {
      if(table[s[i]] < table[s[i+1]]) {
        result += table[s[i+1]] - table[s[i]];
        i += 1;
      } else {
        result += table[s[i]];
      }
    }
    if(table[s[s.size() - 2]] >= table[s[s.size() - 1]]) {
      result += table[s[s.size() - 1]];
    }
    return result;
  }
 private:
  unordered_map<char, int> table;
};
