class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    string result;
    vector<string> data;
    for(auto & num : nums) { data.push_back(to_string(num)); }
    auto comp_lambda = [] (string & a, string & b) {
      return stoull(a + b) > stoull(b + a);
    };
    sort(data.begin(), data.end(), comp_lambda);
    size_t i = 0;
    while(i < data.size() && data[i] == "0") { i ++; }
    while(i < data.size()) {
      result += data[i];
      i ++;
    }
    return result == "" ? "0" : result;
  }
};
