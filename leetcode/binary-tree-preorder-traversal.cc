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
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    if(root == NULL) return result;
    stack<TreeNode*> stk;
    stk.push(root);
    while(!stk.empty()) {
      auto v = stk.top(); stk.pop();
      if(v) result.push_back(v->val);
      if(v->right) stk.push(v->right);
      if(v->left) stk.push(v->left);
    }
    return result;
  }
};
