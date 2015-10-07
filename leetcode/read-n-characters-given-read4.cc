// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {

 public:
  /**
   * @param buf Destination buffer
   * @param n   Maximum number of characters to read
   * @return    The number of characters read
   */
  int read(char *buf, int n) {
    int bytes = 0;
    bool eof = false;
    char tmp[4];
    while(bytes < n && !eof) {
      int sz = read4(tmp);
      if(sz < 4) eof = true;
      sz = min(n - bytes, sz);
      memcpy(buf + bytes, tmp, sz);
      bytes += sz;
    }
    return bytes;
  }
};
