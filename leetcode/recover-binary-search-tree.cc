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
  void inorder(TreeNode *v) {
    if(v == NULL) return;
    inorder(v->left);
    if(prev == NULL) prev = v;
    if(prev->val > v->val) {
      if(first == NULL) {
        first = prev;
      }
      second = v;
    }
    prev = v;
    inorder(v->right);
  }

  void recoverTree(TreeNode* root) {
    prev = NULL; first = NULL; second = NULL;
    inorder(root);
    int tmp = first->val;
    first->val = second->val;
    second->val = tmp;
  }

 private:
  TreeNode *prev, *first, *second;
};
