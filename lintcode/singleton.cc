class Solution {
 public:
  Solution() {}
  ~Solution() {}

  // Noncopyable.
  Solution(const Solution&) = delete;
  Solution& operator=(const Solution&) = delete;

  /**
   * @return: The same instance of this class every
   * time
   */
  static Solution* getInstance() {
    // write your code here
    static Solution *instance = new Solution();
    return instance;
  }

};
