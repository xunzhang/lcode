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
  vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> result;
    if(intervals.size() == 0) return result;
    auto comp_lambda = [] (Interval a, Interval b) {
      if(a.start < b.start) return true;
      if(a.start > b.start) return false;
      return a.end < b.end;
    };
    sort(intervals.begin(), intervals.end(), comp_lambda);
    result.push_back(intervals[0]);
    for(size_t p = 1; p < intervals.size(); ++p) {
      int left = result.back().start, right = result.back().end;
      if(intervals[p].start <= right) {
        result.back().end = max(right, intervals[p].end);
      } else {
        result.push_back(intervals[p]);
      }
    }
    return result;
  }
};
