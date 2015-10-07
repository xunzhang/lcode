class Solution {
 public:
  string intToRoman(int num) {
    string roman;
    int i = 0;
    while(num) {
      int r = num / val[i];
      num -= r * val[i];
      for(int k = 0; k < r; ++k) roman += sym[i];
      i ++;
    }
    return roman;
  }
 private:
  vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  vector<string> sym = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
};
