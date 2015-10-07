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
  bool foo(TreeNode *v, int *lowbar, int *highbar) {
    if(v == NULL) return true;
    return (lowbar == NULL || v->val > *lowbar) && (highbar == NULL || v->val < *highbar) 
        && foo(v->left, lowbar, &v->val) && foo(v->right, &v->val, highbar);
  }

  bool isValidBST(TreeNode* root) {
    int *low = NULL, *high = NULL;
    return foo(root, low, high);
  }
};
