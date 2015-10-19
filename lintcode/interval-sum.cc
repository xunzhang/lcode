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
  // O(A.size() + queries.size())
  vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
    vector<long long> sums(A.size() + 1, 0);
    for(int i = 1; i < sums.size(); ++i) sums[i] = sums[i-1] + A[i-1];
    vector<long long> results;
    for(auto & q : queries) {
      results.push_back(sums[q.end + 1] - sums[q.start]);
    }
    return results;
  }

  // O(A.size() + queries.size() * height)
  vector<long long> intervalSum2(vector<int> &A, vector<Interval> &queries) {
    // write your code here
    vector<long long> sums;
    SegmentTree ST(A);
    for(auto & q : queries) {
      sums.push_back(ST.query(q));
    }
    return sums;
  }

 private:
  class SegmentTreeNode {
   public:
    int start, end;
    long long sum;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, long long sum) {
      this->start = start;
      this->end = end;
      this->sum = sum;
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
      int sm = 0;
      if(end < start) return NULL;
      SegmentTreeNode *p = new SegmentTreeNode(start, end, sm);
      if(start == end) { p->sum = A[start]; return p; }
      int mid = (start + end) / 2;
      p->left = build(A, start, mid);
      p->right = build(A, mid + 1, end);
      p->sum = p->left->sum + p->right->sum;
      return p;
    }

    long long query(Interval it) {
      return query(root, it.start, it.end);
    }

    long long query(SegmentTreeNode *root, int start, int end) {
      if(root == NULL) return 0;
      if(end < start) return 0;
      if(start <= root->start && end >= root->end) {
        return root->sum;
      }
      int mid = (root->start + root->end) / 2;
      return query(root->left, start, min(mid, end)) +
          query(root->right, max(mid + 1, start), end);
    }

   private:
    SegmentTreeNode *root;
  };
};

