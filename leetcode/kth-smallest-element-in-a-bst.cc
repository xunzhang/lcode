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
  // O(k) solution
  int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode *> stk;
    int cnt = 0;
    while(root) {
      stk.push(root);
      root = root->left;
    }
    while(!stk.empty()) {
      TreeNode *node = stk.top();
      stk.pop();
      cnt += 1;
      if(cnt == k) return node->val;
      TreeNode *tmp = node->right;
      while(tmp) {
        stk.push(tmp);
        tmp = tmp->left;
      }
    }
  }
  // O(h * N)
  int kthSmallest(TreeNode *root, int k) {
    int cnt = count(root->left);
    if(k <= cnt) {
      return kthSmallest(root->left, k);
    } else if(k > cnt + 1) {
      return kthSmallest(root->right, k - cnt - 1);
    } else {
      return root->val;
    }
  }
  int count(TreeNode *v) {
    if(v == NULL) return 0;
    return count(v->left) + count(v->right) + 1;
  }
};
