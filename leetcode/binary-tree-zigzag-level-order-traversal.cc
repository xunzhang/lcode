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
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if(root == NULL) return result;
    queue<pair<TreeNode*, int> > q;
    q.push(make_pair(root, 0));
    while(!q.empty()) {
      auto tmp = q.front(); q.pop();
      auto node = tmp.first;
      int dep = tmp.second;
      if(result.size() <= dep) result.resize(dep + 1);
      result[dep].push_back(node->val);
      if(node->left) q.push(make_pair(node->left, dep + 1));
      if(node->right) q.push(make_pair(node->right, dep + 1));
    }
    for(int i = 1; i < result.size(); i += 2) {
      reverse(result[i].begin(), result[i].end());
    }
    return result;
  }
};
