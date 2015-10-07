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
    while(bytes < n && !eof) {
      if(buffer_sz == 0) {
        int rsz = read4(buffer);
        if(rsz < 4) eof = true;
        buffer_sz += rsz;
      }
      int sz = min(n - bytes, buffer_sz);
      memcpy(buf + bytes, buffer + buffer_offset, sz);
      buffer_offset = (buffer_offset + sz) % 4;
      buffer_sz -= sz;
      bytes += sz;
    }
    return bytes;
  }

 private:
  char buffer[4];
  int buffer_offset = 0;
  int buffer_sz = 0;
};
