class Solution {

 public:
  bool canPermutePalindrome(string s) {
    unordered_set<char> SS;
    for(auto & ch : s) {
      if(SS.count(ch)) {
        SS.erase(ch);
      } else {
        SS.insert(ch);
      }
    }
    return SS.size() <= 1;
  }
};
