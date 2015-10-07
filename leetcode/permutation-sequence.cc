class Solution {
 public:
  string getPermutation(int n, int k) {
    string result, data;
    for(int i = 1; i <= n; ++i) data.push_back(i + '0');
    vector<int> fac(n, 1);
    for(int i = 2; i < n; ++i) fac[i] = i * fac[i-1];
    for(int i = n - 1; i >= 1; --i) {
      int indx = (k-1) / fac[i];
      result.push_back(data[indx]);
      data.erase(data.begin() + indx);
      k -= indx * fac[i];
    }
    result.push_back(data[0]);
    return result;
  }
};
