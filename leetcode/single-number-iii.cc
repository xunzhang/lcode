class Solution {

 public:
  vector<int> singleNumber(vector<int>& nums) {
    vector<int> two(2, 0);
    int v = 0;
    for(auto & num : nums) v ^= num;
    int rbits = 0;
    while(v) {
      if(v % 2 == 1) break;
      v /= 2;
      rbits += 1;
    }
    for(int i = 0; i < nums.size(); ++i) {
      if((nums[i] >> rbits) % 2) {
          two[0] ^= nums[i];
      } else {
        two[1] ^= nums[i];
      }
    }
    return two;
  }
};
