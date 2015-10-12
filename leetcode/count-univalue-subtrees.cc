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
  bool bt(TreeNode *root, int & cnt) {
    if(root == NULL) return true;
    if(root->left == NULL && root->right == NULL) { cnt ++; return true; }
    int lflag = bt(root->left, cnt);
    int rflag = bt(root->right, cnt);
    if(lflag && rflag) {
      int lv = root->left ? root->left->val : root->val;
      int rv = root->right ? root->right->val : root->val;
      if(root->val == lv && root->val == rv) {
        cnt += 1;
        return true;
      }
      return false;
    } else {
      return false;
    }
  }

  int countUnivalSubtrees(TreeNode* root) {
    if(root == NULL) return 0;
    int cnt = 0;
    bt(root, cnt);
    return cnt;
  }
};
