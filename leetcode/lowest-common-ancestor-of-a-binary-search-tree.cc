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
  // trace path
  vector<TreeNode*> foo(TreeNode *root, TreeNode *a) {
    vector<TreeNode*> path;
    while(root != a) {
      path.push_back(root);
      root = root->val < a->val ? root->right : root->left;
    }
    path.push_back(a);
    return path;
  }

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL) return NULL;
    auto path1 = foo(root, p);
    auto path2 = foo(root, q);
    int bound = min(path1.size(), path2.size());
    int i = 1;
    while(i < bound) {
      if(path1[i] != path2[i]) break;
      ++i;
    }
    return path1[i-1];
  }
};
