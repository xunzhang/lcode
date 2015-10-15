#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
 public:
  /**
   * @param A: An integer array.
   * @return: void
   */
  void rerange(vector<int> &A) {
    // write your code here
    if(A.size() < 2) return;
    int indx = 2;
    for(int i = 1; i < A.size() && indx < A.size();)
    {
      if(A[i] * A[0] > 0) {
        swap(A[indx], A[i]);
        indx += 2;
      } else {
        i += 2;
      }
    }
    if(A[A.size()-2] * A[A.size()-1] > 0) {
      int save = A[A.size()-1];
      for(int i = A.size() - 1; i > 0; --i) A[i] = A[i-1];
      A[0] = save;
    }
  }
};

int main(int argc, char *argv[])
{
  Solution o;
  vector<int> A = {-1, -2, 1, -2, -2};
  o.rerange(A);
  for(auto & v : A) cout << v << endl;
  return 0;
}
