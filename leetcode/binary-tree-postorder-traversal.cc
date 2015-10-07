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
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> stk;
    while(1) {
      while(root) { stk.push(root); root = root->left; }
      while(!stk.empty() && stk.top()->right == root) {
        root = stk.top();
        stk.pop();
        result.push_back(root->val);
      }
      if(stk.empty()) break;
      root = stk.top()->right;
    }
    return result;
  }
};
