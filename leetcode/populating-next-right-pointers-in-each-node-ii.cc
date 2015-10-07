/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

class Solution {
 public:
  void connect(TreeLinkNode *root) {
    if(root == NULL) return;
    TreeLinkNode *it = root->next, *tmp = NULL;
    while(it) {
      if(it->left) { tmp = it->left; break; }
      if(it->right) { tmp = it->right; break; }
      it = it->next;
    }
    if(root->left && root->right) {
      root->left->next = root->right;
      root->right->next = tmp;
    } else
      if(root->left) {
        root->left->next = tmp;
      } else if(root->right) {
        root->right->next = tmp;
      } else {
        return;
      }
    connect(root->right);
    connect(root->left);
  }
};
