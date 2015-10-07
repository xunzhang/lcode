class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    vector<int> result = digits;
    int indx = result.size() - 1;
    while(indx >= 0) {
      if(result[indx] == 9) {
        result[indx] = 0;
        indx -= 1;
      } else {
        std::cout << indx << std::endl;
        std::cout << result[indx] << std::endl;
        result[indx] += 1;
        return result;
      }
    }
    result.insert(result.begin(), 1);
    return result;
  }
};
