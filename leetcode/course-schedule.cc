class Solution {

 public:
  bool canFinish_dfs(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> vp; vp.resize(numCourses);
    for(auto & pr : prerequisites) vp[pr.second].push_back(pr.first);
    while(1) {
      // every round
      bool isEmpty = true;
      unordered_set<int> B;
      for(int i = 0; i < numCourses; ++i) {
        if(vp[i].size() != 0) {
          isEmpty = false;
          int left = i, right = vp[i].back();
          vp[i].pop_back();
          B.insert(left);
          while(vp[right].size() != 0) {
            left = right;
            int tmp = vp[right].back();
            vp[right].pop_back();
            for(auto & vv : vp[right]) if(B.count(vv)) return false;
            right = tmp;
            if(B.count(right)) return false;
            B.insert(left);
          }
          break;
        }
      }
      if(isEmpty) break;
    }
    return true;
  }

  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    if(prerequisites.size() == 0) return true;
    vector<unordered_set<int>> reverseArrow; reverseArrow.resize(numCourses);
    unordered_map<int, vector<int>> M;
    for(auto & pr : prerequisites) {
      reverseArrow[pr.first].insert(pr.second);
      M[pr.second].push_back(pr.first);
    }
    unordered_set<int> insideSet;
    int cnt = 0;
    while(1) {
      bool exist = false;
      for(int i = 0; i < numCourses; ++i) {
        if(insideSet.count(i)) continue;
        if(reverseArrow[i].size() == 0) {
          exist = true;
          insideSet.insert(i);
          for(auto & j : M[i]) reverseArrow[j].erase(i);
          break;
        }
      }
      if(!exist) return false;
      cnt ++;
      if(cnt == numCourses) return true;
    }
  }
};
