class NumArray {
 public:
  NumArray(vector<int> &nums) {
    sums.resize(nums.size() + 1, 0);
    for(int i = 1; i <= nums.size(); ++i) sums[i] = nums[i-1] + sums[i-1];
  }

  int sumRange(int i, int j) {
    return sums[j + 1] - sums[i];
  }

 private:
  vector<int> sums;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
