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
  int closestValue(TreeNode* root, double target) {
    if(target < root->val) {
      if(root->left == NULL) return root->val;
      int ln = closestValue(root->left, target);
      return abs(ln - target) < root->val - target ? ln : root->val;
    } else if(target > root->val) {
      if(root->right == NULL) return root->val;
      int rn = closestValue(root->right, target);
      return abs(rn - target) < target - root->val ? rn : root->val;
    } else return root->val;
  }
};
