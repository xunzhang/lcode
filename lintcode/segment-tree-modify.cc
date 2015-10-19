/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
 public:
  /**
   *@param root, index, value: The root of segment tree and 
   *@ change the node's value with [index, index] to the new
   given value
   *@return: void
   */
  void modify(SegmentTreeNode *root, int index, int value) {
    // write your code here
    if(index > root->end || index < root->start) return;
    if(root->left == root->right) {
      root->max = value;
      return;
    }
    int mid = (root->start + root->end) / 2;
    if(index <= mid) {
      modify(root->left, index, value);
      root->max = max(root->left->max, root->right->max);
    } else {
      modify(root->right, index, value);
      root->max = max(root->left->max, root->right->max);
    }
  }
};

