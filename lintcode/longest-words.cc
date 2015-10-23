class Solution {
 public:
  /**
   * @param dictionary: a vector of strings
   * @return: a vector of strings
   */
  vector<string> longestWords(vector<string> &dictionary) {
    // write your code here
    vector<string> r;
    if(dictionary.size() == 0) return r;
    r.push_back(dictionary[0]);
    int mx = dictionary[0].size();
    for(int i = 1; i < dictionary.size(); ++i) {
      if(dictionary[i].size() > mx) {
        mx = dictionary[i].size();
        r.resize(0);
        r.push_back(dictionary[i]);
      } else if(dictionary[i].size() == mx) {
        r.push_back(dictionary[i]);
      }
    }
    return r;
  }
};

