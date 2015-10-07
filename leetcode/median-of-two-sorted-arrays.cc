class Solution {
 public:
  double kth(int A[], int m, int B[], int n, int k) {
    if(m == 0) return B[k-1];
    if(n == 0) return A[k-1];
    if(m / 2 + n / 2 < k - 1) {
      if(A[m/2] < B[n/2]) {
        return kth(A + m / 2 + 1, m - (m / 2 + 1), B, n, k - (m / 2 + 1));
      }
      else {
        return kth(A, m, B + n / 2 + 1, n - (n / 2 + 1), k - (n /  2 + 1));
      }
    } else {
      if(A[m/2] < B[n/2]) {
        return kth(A, m, B, n / 2, k);
      } else {
        return kth(A, m / 2, B, n, k);
      }
    }
  }

  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    size_t m = nums1.size(), n = nums2.size();
    return (m + n) % 2 == 0 
        ? (kth(&nums1[0], nums1.size(), &nums2[0], nums2.size(), (m + n) / 2) + kth(&nums1[0], nums1.size(), &nums2[0], nums2.size(), (m + n) / 2 + 1)) / 2 
        : kth(&nums1[0], nums1.size(), &nums2[0], nums2.size(), (m + n) / 2 + 1);
  }
};
