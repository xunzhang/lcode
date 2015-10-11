/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {

 public:
  bool canAttendMeetings(vector<Interval>& intervals) {
    if(intervals.size() == 0) return true;
    auto cmp_lambda = [] (Interval a, Interval b) {
      if(a.start != b.start) return a.start < b.start;
      else return a.end < b.end;
    };
    sort(intervals.begin(), intervals.end(), cmp_lambda);
    int right = intervals[0].end;
    for(int i = 1; i < intervals.size(); ++i) {
      if(intervals[i].start < right) return false;
      else right = intervals[i].end;
    }
    return true;
  }
};
