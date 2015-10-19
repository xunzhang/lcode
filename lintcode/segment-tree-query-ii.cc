/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, count;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int count) {
 *         this->start = start;
 *         this->end = end;
 *         this->count = count;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
 public:
  /**
   *@param root, start, end: The root of segment tree and 
   *                         an segment / interval
   *@return: The count number in the interval [start, end] 
   */
  int query(SegmentTreeNode *root, int start, int end) {
    // write your code here
    if(root == NULL) return 0;
    if(end < start) return 0;
    if(start <= root->start && end >= root->end)
      return root->count;
    int mid = (root->start + root->end) / 2;
    return query(root->left, start, min(mid, end)) +
        query(root->right, max(mid + 1, start), end);
  }
};

