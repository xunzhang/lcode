class Solution {
 public:
  vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
    // write your code here
    vector<int> results;
    //sort(A.begin(), A.end()); // O(nlogn)
    SegmentTree ST;
    for(auto & v : A) ST.modify(v, 1);
    for(auto & q : queries) {
      //results.push_back(iterSearch(A, q));
      //results.push_back(binarySearch(A, q));
      results.push_back(ST.query(0, q - 1));
    }
    return results;
  }

  // O(n) per query
  int iterSearch(vector<int> & A, int query) {
    int cnt = 0;
    for(auto & v : A) if(v < query) cnt ++;
    return cnt;
  }

  // O(logn) per query
  int binarySearch(vector<int> & A, int query) {
    int s = 0, e = A.size() - 1;
    while(s <= e) {
      int m = s + (e - s) / 2;
      if(A[m] > query) {
        e = m - 1;
      } else if(A[m] < query) {
        s = m + 1;
      } else {
        int j = m;
        while(j >= 0 && A[j-1] == A[j]) --j;
        return j;
      }
    }
    return s;
  }

 private:
  class SegmentTreeNode {
   public:
    int start, end;
    long long count;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, long long count) {
      this->start = start;
      this->end = end;
      this->count = count;
      this->left = this->right = NULL;
    }
  };

  class SegmentTree {
   public:
    SegmentTree() {
      root = build(0, 10000);
    }

    SegmentTreeNode *build(int start, int end) {
      int cnt = 0;
      if(end < start) return NULL;
      SegmentTreeNode *p = new SegmentTreeNode(start, end, cnt);
      if(start == end) return p;
      int mid = (start + end) / 2;
      p->left = build(start, mid);
      p->right = build(mid + 1, end);
      p->count = p->left->count + p->right->count;
      return p;
    }

    long long query(int start, int end) {
      return query(root, start, end);
    }

    long long query(SegmentTreeNode *root, int start, int end) {
      if(root == NULL) return 0;
      if(end < start) return 0;
      if(start <= root->start && end >= root->end) {
        return root->count;
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
        root->count += value;
        return;
      }
      int mid = (root->start + root->end) / 2;
      if(index <= mid) {
        modify(root->left, index, value);
        root->count = root->left->count + root->right->count;
      } else {
        modify(root->right, index, value);
        root->count = root->left->count + root->right->count;
      }
    }

   private:
    SegmentTreeNode *root;
  };
};

