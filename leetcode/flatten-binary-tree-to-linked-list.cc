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
  void flatten(TreeNode* root) {
    if(root == NULL) return;
    TreeNode *tmp = root->right;
    TreeNode *it = root->left;
    if(it) {
      while(it->right) { it = it->right; }
      it->right = root->right;
      root->right = root->left;
      flatten(root->left);
      root->left = NULL;
    }
    flatten(tmp);
  }
};
