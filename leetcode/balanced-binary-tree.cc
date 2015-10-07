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
  int depth(TreeNode *v) {
    if(v == NULL) return 0;
    int l = depth(v->left);
    int r = depth(v->right);
    return l < r ? r + 1 : l + 1;
  }

  bool isBalanced(TreeNode* root) {
    if(root == NULL) return true;
    int lh = depth(root->left);
    int rh = depth(root->right);
    if(abs(lh - rh) <= 1) {
      return isBalanced(root->left) && isBalanced(root->right);
    }
    return false;
  }
};
