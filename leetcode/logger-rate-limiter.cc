class Logger {
 public:
  /** Initialize your data structure here. */
  Logger() {}

  /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
    If this method returns false, the message will not be printed.
    The timestamp is in seconds granularity. */
  bool shouldPrintMessage(int timestamp, string message) {
    auto it = M.find(message);
    if(it != M.end()) {
      if(timestamp - M[message] < 10) {
        return false;
      }
    }
    M[message] = timestamp;
    return true;
  }

 private:
  unordered_map<string, int> M;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */
