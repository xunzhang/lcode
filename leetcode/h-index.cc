class Solution {

 public:
  int hIndex2(vector<int>& citations) {
    sort(citations.begin(), citations.end());
    int hindx = citations.size();
    for(int i = 0; i < citations.size(); ++i) {
      if(citations[i] < hindx) hindx --;
    }
    return hindx;
  }

  int hIndex(vector<int>& citations) {
    vector<int> record(citations.size() + 1, 0);
    for(auto & v : citations) {
      if(v >= citations.size()) {
        record[citations.size()] ++;
      } else {
        record[v] ++;
      }
    }
    int hindx = record.back();
    for(int i = citations.size() - 1; i >= 0; --i) {
      if(hindx + record[i] <= i) {
        hindx += record[i];
      } else {
        hindx = max(hindx, i);
      }
    }
    return hindx;
  }
};
