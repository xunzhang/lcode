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
  void bt(TreeNode *v, string path, vector<string> & paths) {
    if(v == NULL) return;
    if(v->left == NULL && v->right == NULL) {
      paths.push_back(path+to_string(v->val));
    } else {
      bt(v->left, path + to_string(v->val) + "->", paths);
      bt(v->right, path + to_string(v->val) + "->", paths);
    }
  }

  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> paths;
    string path;
    bt(root, path, paths);
    return paths;
  }
};
