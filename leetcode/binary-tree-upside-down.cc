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
  // bottom up recursive solution
  TreeNode* upsideDownBinaryTree(TreeNode* root) {
    return foo(root, NULL);
  }

  TreeNode* foo(TreeNode *child, TreeNode *parent) {
    if(child == NULL) return parent;
    auto rightest = foo(child->left, child);
    child->left = parent == NULL ? NULL : parent->right;
    child->right = parent;
    return rightest;
  }
};
