class Solution {

 public:
  // O(N*logN)
  vector<int> maxSlidingWindow_heap(vector<int>& nums, int k) {
    priority_queue<pair<int, int>> H;
    vector<int> result;
    if(k == 0 || nums.size() == 0) return result;
    for(int i = 0; i < k; ++i) H.push(make_pair(nums[i], i));
    result.push_back(H.top().first);
    for(int i = k; i < nums.size(); ++i) {
      while(!H.empty() && H.top().second <= i - k) H.pop();
      H.push(make_pair(nums[i], i));
      result.push_back(H.top().first);
    }
    return result;
  }

  // save all currently potential "maximum" elements: all elements in dk is larger than nums[i]
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> dk;
    for(int i = 0; i < nums.size(); ++i) {
      while(!dk.empty() && nums[i] > nums[dk.back()]) dk.pop_back();
      dk.push_back(i);
      if(i >= k - 1) result.push_back(nums[dk.front()]);
      if(dk.front() + k - 1 <= i) dk.pop_front();
    }
    return result;
  }
};
