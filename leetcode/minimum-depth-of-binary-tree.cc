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
  int minDepth(TreeNode* root) {
    if(root == NULL) return 0;
    vector<vector<int>> hp;
    queue<pair<TreeNode*, int> > q;
    q.push(make_pair(root, 0));
    while(!q.empty()) {
      auto tmp = q.front(); q.pop();
      auto node = tmp.first;
      int dep = tmp.second;
      if(node->left == NULL && node->right == NULL) return dep + 1;
      if(hp.size() <= dep) hp.resize(dep+1);
      hp[dep].push_back(1);
      if(node->left) q.push(make_pair(node->left, dep + 1));
      if(node->right) q.push(make_pair(node->right, dep + 1));
    }
  }

  int minDepth(TreeNode* root) {
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    int l = minDepth(root->left), r = minDepth(root->right);
    if(root->left == NULL) {
      return r + 1;
    } else
      if(root->right == NULL) {
        return l + 1;
      } else {
        return min(l, r) + 1;
      }
  }
};
