class Solution {
 public:
  /** 
   * @param chars: The letters array you should sort.
   */
  void sortLetters(string &letters) {
    // write your code here
    int indx = letters.size() - 1;
    for(int i = 0; i < letters.size() && i < indx;) {
      if(letters[i] >= 'A' && letters[i] <= 'Z') {
        swap(letters[i], letters[indx]);
        indx -= 1;
      } else {
        ++i;
      }
    }
  }
};


