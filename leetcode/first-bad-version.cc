// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {

 public:
  int firstBadVersion(int n) {
    int s = 1, e = n;
    int mid;
    while(s <= e) {
      mid = s + (e - s) / 2;
      if(isBadVersion(mid)) {
        //if(mid == 0) return 0;
        if(mid >= 1 && !isBadVersion(mid-1)) return mid; 
        e = mid - 1;
      } else {
        s = mid + 1;
      }
    }
    return mid;
  }
};
