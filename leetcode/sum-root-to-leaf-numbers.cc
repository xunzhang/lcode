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
  void dfs(TreeNode *v, int sum, int & result) {
    if(v->left == NULL && v->right == NULL) { 
      result += sum + v->val;
      return;
    }
    sum += v->val;
    if(v->left) dfs(v->left, sum * 10, result);
    if(v->right) dfs(v->right, sum * 10, result);
  }
  int sumNumbers(TreeNode* root) {
    if(root == NULL) return 0;
    int result = 0;
    dfs(root, 0, result);
    return result;
  }
};
