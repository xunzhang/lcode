class Solution {
 public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int area = (C-A) * (D-B) + (G-E) * (H-F);
    if(E < A) return computeArea(E, F, G, H, A, B, C, D);
    int x1, y1, x2, y2;
    if(E >= A && E <= C) {
      x1 = E, x2 = min(C, G);
      if(D < F || B > H) return area;
      y1 = max(B, F);
      y2 = min(D, H);
      return area - (x2 - x1) * (y2 - y1);
    }
    else {
      return area;
    }
  }
};
