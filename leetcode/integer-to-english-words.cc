class Solution {

 public:
  Solution() {
    Name[1] = "One"; Name[2] = "Two"; Name[3] = "Three";
    Name[4] = "Four"; Name[5] = "Five"; Name[6] = "Six";
    Name[7] = "Seven"; Name[8] = "Eight"; Name[9] = "Nine";
  }

  string numberToWords(int num) {
    if(num == 0) return "Zero";
    string result;
    while(num) {
      for(int i = 0; i < Digit.size(); ++i) {
        int v = num / Digit[i];
        if(v) {
          if(i < 4) {
            if(!Name.count(v)) {
              result += numberToWords(v) + " ";
            } else {
              result += Name[v] + " ";
            }
          }
          result += English[i] + " ";
          num -= v * Digit[i];
        }
      }
    }
    return result.substr(0, result.size()-1);
  }

 private:
  unordered_map<int, string> Name;
  vector<int> Digit = {1000000000, 1000000, 1000, 100,
    90, 80, 70, 60, 50, 40, 30, 20,
    19, 18, 17, 16, 15, 14, 13, 12, 11, 10,
    9, 8, 7, 6, 5, 4, 3, 2, 1};

  vector<string> English = {"Billion", "Million", "Thousand", "Hundred",
    "Ninety", "Eighty", "Seventy", "Sixty", "Fifty", "Forty", "Thirty", "Twenty",
    "Nineteen", "Eighteen", "Seventeen", "Sixteen", "Fifteen", "Fourteen", "Thirteen", "Twelve", "Eleven", "Ten",
    "Nine", "Eight", "Seven", "Six", "Five", "Four", "Three", "Two", "One"};
};
