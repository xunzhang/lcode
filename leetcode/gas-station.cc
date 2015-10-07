class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int sum = 0;
    int indx = 0;
    for(int i = 0; i < gas.size(); ++i) { sum += gas[i] - cost[i]; }
    if(sum < 0) return -1;
    sum = 0;
    for(int i = 0; i < gas.size(); ++i) {
      sum += gas[i] - cost[i];
      if(sum < 0) {
        sum = 0;
        indx = i + 1;
      }
    }
    if(indx == gas.size()) indx = 0;
    return indx;
  }
};
