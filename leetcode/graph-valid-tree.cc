class Solution {

 public:
  // O(n*n)
  bool validTree2(int n, vector<pair<int, int>>& edges) {
    vector<int> data;
    for(int i = 0; i < n; ++i) data.push_back(i);
    for(auto & edge : edges) {
      int u = edge.first, v = edge.second;
      if(data[u] == data[v]) return false;
      else {
        for(int i = 0; i < data.size(); ++i) {
          if(i == u) continue;
          if(data[i] == data[u]) data[i] = data[v];
        }
        data[u] = data[v];
      }
    }
    for(int i = 0 ; i < data.size() - 1; ++i) {
      if(data[i] != data[i+1])
        return false;
    }
    return true;
  }

  int root(vector<int> data, int a) {
    while(data[a] != a) a = data[a];
    return a;
  }

  bool validTree(int n, vector<pair<int, int>>& edges) {
    if(edges.size() != n - 1) return false;
    vector<int> data;
    for(int i = 0; i < n; ++i) data.push_back(i);
    for(auto & edge : edges) {
      int u = edge.first, v = edge.second;
      if(root(data, u) == root(data, v)) return false;
      else data[v] = root(data, u);
    }
    return true;
  }
};
