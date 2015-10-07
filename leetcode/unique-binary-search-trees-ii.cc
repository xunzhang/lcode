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
  vector<TreeNode*> foo(int l, int r) {
    vector<TreeNode*> trees;
    if(l > r) { trees.push_back(NULL); return trees; }
    for(int k = l; k <= r; ++k) {
      auto ltrees = foo(l, k - 1);
      auto rtrees = foo(k + 1, r);
      for(auto & ltree : ltrees) {
        for(auto & rtree : rtrees) {
          TreeNode *root = new TreeNode(k);
          root->left = ltree;
          root->right = rtree;
          trees.push_back(root);
        }
      }
    }
    return trees;
  }

  vector<TreeNode*> generateTrees(int n) {
    return foo(1, n);
  }
};
