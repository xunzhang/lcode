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
  int maxPathSum(TreeNode* root) {
    foo(root);
    return max_sum;
  }
  // suppose max sum path go through node v as an internal node
  int foo(TreeNode *v) {
    if(v == NULL) return 0;
    int lmax = foo(v->left);
    int rmax = foo(v->right);
    max_sum = max(max_sum, v->val + lmax + rmax);
    int ret = v->val + max(lmax, rmax);
    return max(ret, 0);
  }
 private:
  int max_sum = INT_MIN;
};
