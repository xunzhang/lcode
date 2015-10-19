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
   *@param root, start, end: The root of segment tree and 
   *                         an segment / interval
   *@return: The maximum number in the interval [start, end]
   */
  int query(SegmentTreeNode *root, int start, int end) {
    // write your code here
    if(root == NULL) return INT_MIN;
    if(end < start) return INT_MIN;
    if(start <= root->start && end >= root->end) {
      return root->max;
    }
    int mid = (root->start + root->end) / 2;
    return max(query(root->left, start, min(mid, end)),
               query(root->right, max(mid + 1, start), end));
  }
};
