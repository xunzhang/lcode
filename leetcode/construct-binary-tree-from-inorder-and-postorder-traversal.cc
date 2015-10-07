class Solution {
 public:
  TreeNode* rec(int a[], int m, int b[], int n) {
    if(m == 0) return NULL;
    TreeNode *node = new TreeNode(b[n-1]);
    int indx = 0;
    while(a[indx] != b[n-1]) indx++;
    node->left = rec(a, indx, b, indx);
    node->right = rec(a + indx + 1, m - indx - 1, b + indx, n - 1 - indx);
    return node;
  }

  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(inorder.size() == 0) return NULL;
    int N = inorder.size();
    int a[N], b[N];
    for(int i = 0; i < N; ++i) { a[i] = inorder[i]; b[i] = postorder[i]; }
    return rec(a, N, b, N);
  }
};
