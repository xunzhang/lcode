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
  TreeNode* inorderSuccessor_binarytree(TreeNode* root, TreeNode* p) {
    if(root == NULL || p == NULL) return NULL;
    stack<TreeNode *> stk;
    TreeNode *it = root;
    while(it) { stk.push(it); it = it->left; }
    while(1) {
      TreeNode *tmp = stk.top();
      stk.pop();
      TreeNode *r = tmp->right;
      if(r) {
        stk.push(r);
        while(r->left) {
          stk.push(r->left);
          r = r->left;
        }
      }
      if(tmp == p) return stk.empty() ? NULL : stk.top();
    }
  }

  // use property of BST and no stack, O(h)
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    if(root == NULL || p == NULL) return NULL;
    if(p->right) {
      return findMin(p->right);
    } else {
      TreeNode *succ;
      while(root) {
        if(root->val < p->val) {
          root = root->right;
        } else if(root->val > p->val) {
          succ = root;
          root = root->left;
        } else {
          break;
        }
      }
      return succ;
    }
  }
};
