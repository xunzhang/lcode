/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
 public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> nodes;
    if(root == NULL) return nodes;
    vector<vector<int>> tmp;
    queue<pair<TreeNode *, int>> q;
    q.push(make_pair(root, 0));
    while(!q.empty()) {
      auto pr = q.front(); q.pop();
      auto node = pr.first;
      int level = pr.second;
      if(level >= tmp.size()) tmp.resize(level+1);
      tmp[level].push_back(node->val);
      if(node->left) q.push(make_pair(node->left, level + 1));
      if(node->right) q.push(make_pair(node->right, level + 1));
    }
    for(int i = 0; i < tmp.size(); ++i) { 
      nodes.push_back(tmp[i].back()); 
    }
    return nodes;
  }
};
