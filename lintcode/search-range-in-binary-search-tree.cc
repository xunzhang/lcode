/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {

 public:
  /**
   * @param root: The root of the binary search tree.
   * @param k1 and k2: range k1 to k2.
   * @return: Return all keys that k1<=key<=k2 in ascending
   * order.
   */
  vector<int> searchRange(TreeNode* root, int k1, int k2) {
    // write your code here
    vector<int> vals;
    if(root == NULL) return vals;
    foo(root, k1, k2, vals);
    return vals;
  }

  void foo(TreeNode *p, int k1, int k2, vector<int> & vals) {
    if(p == NULL) return;
    // left subtree with cond
    if(k1 < p->val) {
      foo(p->left, k1, k2, vals);
    }
    if(p->val >= k1 && p->val <= k2) {
      vals.push_back(p->val);
    }
    // right subtree with cond
    if(k2 > p->val) {
      foo(p->right, k1, k2, vals);
    }
  }
};

