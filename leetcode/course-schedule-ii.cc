class Solution {

 public:
  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> seq, null;
    if(prerequisites.size() == 0) {
      for(int i = 0; i < numCourses; ++i) null.push_back(i);
      return null;
    }
    vector<unordered_set<int>> reverseArrow; reverseArrow.resize(numCourses);
    unordered_map<int, vector<int>> M;
    for(auto & pr : prerequisites) {
      reverseArrow[pr.first].insert(pr.second);
      M[pr.second].push_back(pr.first);
    }
    unordered_set<int> insideSet;
    while(1) {
      bool exist = false;
      for(int i = 0; i < numCourses; ++i) {
        if(insideSet.count(i)) continue;
        if(reverseArrow[i].size() == 0) {
          exist = true;
          insideSet.insert(i);
          seq.push_back(i);
          for(auto & j : M[i]) reverseArrow[j].erase(i);
          break;
        }
      }
      if(!exist) return null;
      if(seq.size() == numCourses) return seq;
    }
  }
};
