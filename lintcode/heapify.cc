// 注意建堆复杂度O(n)

class Solution {
 public:
  /**
   * @param A: Given an integer array
   * @return: void
   */
  void heapify(vector<int> &A) {
    // write your code here
    for(int i = A.size() / 2 - 1; i >= 0; --i) {
      sink(A, i);
    }
    /* O(nlogn), n times insert operation
       for(int i = 0; i < A.size(); ++i) {
       swim(A, i); 
       }
     */
  }

 private:
  void sink(vector<int> & A, int indx) {
    int left = indx * 2 + 1, right = indx * 2 + 2;
    int smallest = indx;
    if(left < A.size() && A[indx] > A[left]) smallest = left;
    if(right < A.size() && A[smallest] > A[right]) smallest = right;
    if(smallest != indx) {
      swap(A[smallest], A[indx]);
      sink(A, smallest);
    }
  }

  void swim(vector<int> & A, int indx) {
    int parent = (indx - 1) / 2;
    while(A[parent] > A[indx]) {
      swap(A[parent], A[indx]);
      indx = parent;
      parent = (indx - 1) / 2;
    }   
  }

};

