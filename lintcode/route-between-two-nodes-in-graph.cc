/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
 public:
  /**
   * @param graph: A list of Directed graph node
   * @param s: the starting Directed graph node
   * @param t: the terminal Directed graph node
   * @return: a boolean value
   */
  bool hasRoute(vector<DirectedGraphNode*> graph,
                DirectedGraphNode* s, DirectedGraphNode*
                t) {
    // write your code here
    if(s == t) return true;
    S.insert(s);
    for(auto & neighbor : s->neighbors) {
      if(!S.count(neighbor)) {
        if(hasRoute(graph, neighbor, t)) return true;
      }
    }
    return false;
  }
 private:
  unordered_set<DirectedGraphNode*> S;
};



