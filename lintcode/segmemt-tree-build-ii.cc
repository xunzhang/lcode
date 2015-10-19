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
   *@param A: a list of integer
   *@return: The root of Segment Tree
   */
  SegmentTreeNode * build(vector<int>& A) {
    // write your code here
    int N = A.size();
    return build(A, 0, N - 1);
  }

  SegmentTreeNode *build(vector<int>& A, int start, int end) {
    int mx = INT_MIN;
    if(end < start) return NULL;
    SegmentTreeNode *p = new SegmentTreeNode(start, end, mx);
    if(start == end) { p->max = A[start]; return p; }
    int mid = (start + end) / 2;
    p->left = build(A, start, mid);
    p->right = build(A, mid + 1, end);
    p->max = max(p->left->max, p->right->max);
    return p;
  }
};

