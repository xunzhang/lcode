/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {

 public:
  // bfs
  UndirectedGraphNode *cloneGraph_bfs(UndirectedGraphNode *node) {
    if(node == NULL) return NULL;
    UndirectedGraphNode *vnode = new UndirectedGraphNode(node->label);
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> M;
    M[node] = vnode;
    queue<UndirectedGraphNode*> Q;
    Q.push(node);
    while(!Q.empty()) {
      auto nd = Q.front(); Q.pop();
      auto vnd = M[nd];
      for(auto & neighbor : nd->neighbors) {
        if(M.count(neighbor)) {
          vnd->neighbors.push_back(M[neighbor]);
        } else {
          UndirectedGraphNode *newNode = new UndirectedGraphNode(neighbor->label);
          M[neighbor] = newNode;
          vnd->neighbors.push_back(newNode);
          Q.push(neighbor);
        }
      }
    }
    return vnode;
  }

  // dfs
  UndirectedGraphNode* foo(UndirectedGraphNode *node) {
    UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
    MM[node] = newNode;
    for(auto & neighbor : node->neighbors) {
      if(MM.count(neighbor)) {
        newNode->neighbors.push_back(MM[neighbor]);
      } else {
        newNode->neighbors.push_back(foo(neighbor));
      }
    }
    return newNode;
  }

  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if(node == NULL) return NULL;
    return foo(node);
  }

 private:
  unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> MM;
};
