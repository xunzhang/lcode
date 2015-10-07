/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
 public:
  int maxPoints(vector<Point>& points) {
    if(points.size() < 2) return points.size();
    int result = INT_MIN;
    for(size_t i = 0; i < points.size(); ++i) {
      unordered_map<double, int> D;
      int dup = 1;
      D[INT_MIN] = 0;
      for(size_t j = i + 1; j < points.size(); ++j) {
        if(points[i].x == points[j].x && points[i].y == points[j].y) { dup ++; continue; }
        double k = points[i].x == points[j].x 
            ? INT_MAX 
            : static_cast<double>(points[i].y - points[j].y) / static_cast<double>(points[i].x - points[j].x);
        D[k] += 1;
      }
      for(auto & kv : D) {
        result = max(result, kv.second + dup);
      }
    }
    return result;
  }
};
