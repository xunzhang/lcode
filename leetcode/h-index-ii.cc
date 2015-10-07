class Solution {

 public:
  int hIndex(vector<int>& citations) {
    int s = 0, e = citations.size() - 1;
    int mid;
    int hindx = 0;
    while(s <= e) {
      mid = s + (e - s) / 2;
      int vindx = citations.size() - mid;
      if(vindx <= citations[mid]) {
        e = mid - 1;
        hindx = max(hindx, vindx);
      } else {
        // vindx > citations
        s = mid + 1;
      }
    }
    return hindx;
  }
};
