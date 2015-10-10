class ZigzagIterator {

 public:
  ZigzagIterator(vector<int>& v1, vector<int>& v2) {
    KD = 2;
    nums.push_back(v1); nums.push_back(v2);
    for(auto & i : nums) dataSz += i.size();
    it.resize(KD); 
    for(int i = 0; i < KD; ++i) it.push_back(0);
    for(int i = 0; i < KD; ++i) {
      if(nums[i].size() != 0) { dataIndx = i; break; }
    }
  }

  int next() {
    int v = nums[dataIndx][it[dataIndx]];
    it[dataIndx] ++;
    dataIndx = (dataIndx + 1) % KD;
    int cnt = 0;
    while(cnt <= dataSz && it[dataIndx] >= nums[dataIndx].size()){ 
      dataIndx = (dataIndx + 1) % 2; 
      cnt += 1;
    }
    return v;
  }

  bool hasNext() {
    int itSum = 0;
    for(auto & i : it) itSum += i;
    return itSum < dataSz;
  }

 private:
  int KD = 0; // follow up k
  vector<vector<int> > nums;
  vector<int> it;
  int dataIndx = 0;
  int dataSz = 0;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
