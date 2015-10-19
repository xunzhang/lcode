/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution { 
 public:
  /**
   *@param A, queries: Given an integer array and an query list
   *@return: The result list
   */
  vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
    // write your code here
    SegmentTree ST(A);
    vector<int> result;
    for(auto & q : queries) {
      result.push_back(ST.query(q));
    }
    return result;
  }

 private:
  class SegmentTreeNode {
   public:
    int start, end, min;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, int min) {
      this->start = start;
      this->end = end;
      this->min = min;
      this->left = this->right = NULL;
    }
  };

  class SegmentTree {
   public:
    SegmentTree(vector<int> & A) {
      root = build(A);
    }

    SegmentTreeNode * build(vector<int>& A) {
      int N = A.size();
      return build(A, 0, N - 1);
    }

    SegmentTreeNode *build(vector<int>& A, int start, int end) {
      int mn = INT_MAX;
      if(end < start) return NULL;
      SegmentTreeNode *p = new SegmentTreeNode(start, end, mn);
      if(start == end) {
        p->min = A[start];
        return p;
      }
      int mid = (start + end) / 2;
      p->left = build(A, start, mid);
      p->right = build(A, mid + 1, end);
      p->min = min(p->left->min, p->right->min);
      return p;
    }

    int query(Interval it) {
      return query(root, it.start, it.end);
    }

    int query(SegmentTreeNode *root, int start, int end) {
      if(root == NULL) return INT_MAX;
      if(end < start) return INT_MAX;
      if(start <= root->start && end >= root->end) {
          return root->min;
      }
      int mid = (root->start + root->end) / 2;
      return min(query(root->left, start, min(mid, end)),
              query(root->right, max(mid + 1, start), end));
    }

   private:
    SegmentTreeNode *root;
  };

};

