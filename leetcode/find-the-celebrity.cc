// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {

 public:
  int findCelebrity(int n) {
    if(n == 1) return -1;
    int celebrityNotKnows = 0;
    unordered_set<int> S;
    int celebrity = 0;
    for(int i = 1; i < n; ++i) {
      if(!knows(i, celebrity)) {
        celebrityNotKnows = celebrity;
        celebrity = i;
        S.clear();
      } else {
        S.insert(i);
      }
    }
    for(int i = 0; i < n; ++i) {
      if(i == celebrity) continue;
      if(i != celebrityNotKnows) {
        if(knows(celebrity, i)) return -1;
      }
      if(!S.count(i)) {
        if(!knows(i, celebrity)) return -1;
      }
    }
    return celebrity;
  }
};
