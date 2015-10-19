class Solution {
 public:
  /**
   * @param A: An integer vector
   */
  Solution(vector<int> A) {
    // write your code here
    ST = new SegmentTree(A);
  }

  ~Solution() { delete ST; }

  /**
   * @param start, end: Indices
   * @return: The sum from start to end
   */
  long long query(int start, int end) {
    // write your code here
    return ST->query(start, end);
  }

  /**
   * @param index, value: modify A[index] to value.
   */
  void modify(int index, int value) {
    // write your code here
    ST->modify(index, value);
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


    long long query(int start, int end) {
      return query(root, start, end);
    }

    long long query(SegmentTreeNode *root, int start, int end) {
      if(root == NULL) return 0;
      if(end < start) return 0;
      if(start <= root->start && end >= root->end) { 
        return root->sum;
      }
      int mid = (root->start + root->end) / 2;
      return query(root->left, start, min(mid, end))
          + query(root->right, max(mid + 1, start), end);
    }

    void modify(int index, int value) {
      modify(root, index, value);
    }

    void modify(SegmentTreeNode *root, int index, int value) {
      if(index > root->end || index < root->start) return;
      if(root->left == root->right) {
        root->sum = value;
        return;
      }
      int mid = (root->start + root->end) / 2;
      if(index <= mid) {
        modify(root->left, index, value);
        root->sum = root->left->sum + root->right->sum;
      } else {
        modify(root->right, index, value);
        root->sum = root->left->sum + root->right->sum;
      }
    }

   private:
    SegmentTreeNode *root;
  };

 private:
  SegmentTree *ST;

};

