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
  void dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
    if(root == NULL) return;
    if(parent.count(p) && parent.count(q)) return;
    if(root->left) { parent[root->left] = root; dfs(root->left, p, q); }
    if(root->right) { parent[root->right] = root; dfs(root->right, p, q); }
  }

  TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL) return NULL;
    //parent[root] = root;
    dfs(root, p, q);
    vector<TreeNode*> path1, path2;
    while(p != root) { path1.push_back(p); p = parent[p]; }
    while(q != root) { path2.push_back(q); q = parent[q]; }
    path1.push_back(root); path2.push_back(root);
    reverse(path1.begin(), path1.end());
    reverse(path2.begin(), path2.end());
    int i = 1;
    int bound = min(path1.size(), path2.size());
    while(i < bound) {
      if(path1[i] != path2[i]) break;
      ++i;
    }
    return path1[i-1];
  }

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL || root == p || root == q) return root;
    auto a1 = lowestCommonAncestor(root->left, p, q);
    auto a2 = lowestCommonAncestor(root->right, p, q);
    if(a1 != NULL && a2 != NULL) return root;
    return a1 == NULL ? a2 : a1;
  }

 private:
  unordered_map<TreeNode*, TreeNode*> parent;
};
