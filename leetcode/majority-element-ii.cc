class Solution {
 public:
  vector<int> majorityElement(vector<int>& nums) {
    vector<int> result;
    int A, B, A_cnt = 0, B_cnt = 0;
    for(size_t i = 0; i < nums.size(); ++i) {
      if(nums[i] == A) {
        A_cnt ++;
      } else if(nums[i] == B) {
        B_cnt ++;
      } else if(A_cnt == 0) {
        A = nums[i];
        A_cnt = 1;
      } else if(B_cnt == 0) {
        B = nums[i];
        B_cnt = 1;
      } else {
        A_cnt --;
        B_cnt --;
      }
    }
    A_cnt = 0, B_cnt = 0;
    for(auto & num : nums) {
      if(num == A) A_cnt ++;
      if(num == B) B_cnt ++;
    }
    if(A_cnt > nums.size() / 3) result.push_back(A);
    if(B_cnt > nums.size() / 3) result.push_back(B);
    return result;
  }
};
