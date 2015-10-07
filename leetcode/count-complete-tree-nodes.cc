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
  // O(logn * logn)
  int countNodes(TreeNode* root) {
    if(root == NULL) return 0;
    int hl = 0, hr = 0;
    TreeNode *v1 = root, *v2 = root;
    while(v1) { hl += 1; v1 = v1->left; }
    while(v2) { hr += 1; v2 = v2->right; }
    if(hl == hr) return pow(2, hl) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};
