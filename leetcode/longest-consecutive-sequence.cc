class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> S;
    for(auto & num : nums) S.insert(num);
    int longconsecutive = 0;
    for(auto & num : nums) {
      int lv = num - 1, rv = num + 1, cnt = 1;
      while(S.count(lv)) {
        cnt ++;
        S.erase(lv);
        lv -= 1;
      }
      while(S.count(rv)) {
        cnt ++;
        S.erase(rv);
        rv += 1;
      }
      S.erase(num);
      longconsecutive = max(longconsecutive, cnt);
    }
    return longconsecutive;
  }
};
