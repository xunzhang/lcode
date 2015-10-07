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
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> stk;
    while(1) {
      while(root) { stk.push(root); root = root->left; }
      if(stk.empty()) break;
      root = stk.top(); stk.pop();
      result.push_back(root->val);
      root = root->right;
    }
    return result;
  }

  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> stk;
    TreeNode *cur = root;
    while(cur || !stk.empty()) {
      if(cur) {
        stk.push(cur);
        cur = cur->left;
      }
      else {
        // cur == NULL && !stk.empty()
        auto v = stk.top(); stk.pop();
        result.push_back(v->val);
        cur = v->right;
      }
    }
    return result;
  }
};
