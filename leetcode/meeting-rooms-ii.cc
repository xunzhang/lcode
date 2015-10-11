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
  int minMeetingRooms(vector<Interval>& intervals) {
    vector<pair<int, char>> data;
    for(auto & i : intervals) {
      data.push_back(make_pair(i.start, 's'));
      data.push_back(make_pair(i.end, 'e'));
    }
    auto cmp_lambda = [] (pair<int, char> a, pair<int, char> b) {
      if(a.first != b.first) return a.first < b.first;
      else if(a.second == 's' && b.second == 'e') return false;
      else if(a.second == 'e' && b.second == 's') return true;
      else return true;

    };
    sort(data.begin(), data.end(), cmp_lambda);
    int rooms = 0;
    int cnt = 0;
    for(int i = 0; i < data.size(); ++i) {
      if(data[i].second == 's') cnt ++;
      else cnt --;
      rooms = max(rooms, cnt);
    }
    return rooms;
  }
};
