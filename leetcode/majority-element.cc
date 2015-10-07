class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int result = INT_MAX, cnt = 0;
    for(size_t i = 0; i < nums.size(); ++i) {
      if(nums[i] == result) {
        cnt ++;
      } else
        if(cnt == 0) {
          result = nums[i];
          cnt = 1;
        } else {
          cnt --;
        }
    }
    return result;
  }
};
