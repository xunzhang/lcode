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
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> result;
    size_t p = 0;
    while(p < intervals.size() && intervals[p].end < newInterval.start) {
      result.push_back(intervals[p]);
      p ++;
    }
    if(p == intervals.size()) {
      result.push_back(newInterval);
      return result;
    }
    int new_start = min(intervals[p].start, newInterval.start);
    int new_end = newInterval.end;
    while(p < intervals.size() && newInterval.end >= intervals[p].start) {
      new_end = max(newInterval.end, intervals[p].end);
      p ++;
    }
    result.push_back(Interval(new_start, new_end));
    result.insert(result.end(), intervals.begin() + p, intervals.end());
    return result;
  }
};
