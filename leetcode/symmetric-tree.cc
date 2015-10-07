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
  bool isMirror(TreeNode *l, TreeNode *r) {
    if(l == NULL && r == NULL) return true;
    if(l == NULL || r == NULL) return false;
    if(l->val != r->val) {
      return false;
    } else {
      return isMirror(l->right, r->left) && isMirror(l->left, r->right);
    }
  }
  bool isSymmetric(TreeNode* root) {
    if(root == NULL) return true;
    return isMirror(root->left, root->right);
  }
};
