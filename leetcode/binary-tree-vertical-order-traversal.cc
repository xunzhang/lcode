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
  vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> r;
    unordered_map<int, vector<int>> M;
    queue<pair<TreeNode*, int>> Q;
    if(root) Q.push({root, 0});
    while(!Q.empty()) {
      auto tmp = Q.front(); Q.pop();
      M[tmp.second].push_back(tmp.first->val);
      if(tmp.first->left) Q.push({tmp.first->left, tmp.second - 1});
      if(tmp.first->right) Q.push({tmp.first->right, tmp.second + 1});
    }
    vector<int> seq;
    for(auto & kv : M) seq.push_back(kv.first);
    sort(seq.begin(), seq.end());
    for(auto & s : seq) r.push_back(M[s]);
    return r;
  }
};
