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
  TreeNode* rec(int a[], int m, int b[], int n) {
    if(m == 0) return NULL;
    TreeNode *node = new TreeNode(a[0]);
    int indx = 0;
    while(b[indx] != a[0]) indx++;
    node->left = rec(a + 1, indx, b, indx);
    node->right = rec(a + 1 + indx, m - 1 - indx, b + 1 + indx, n - 1 - indx);
    return node;
  }

  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.size() == 0) return NULL;
    int N = preorder.size();
    int a[N], b[N];
    for(int i = 0; i < N; ++i) { a[i] = preorder[i]; b[i] = inorder[i]; }
    return rec(a, N, b, N);
  }
};
