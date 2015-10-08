class Solution {

 public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> lines;
    int indx = 0;
    while(indx < words.size()) {
      int sz = maxWidth;
      string line;
      int offset = indx;
      while(offset < words.size()) {
        if(sz >= static_cast<int>(words[offset].size())) {
          sz = sz - (words[offset].size() + 1);
          offset += 1;
        } else {
          break;
        }
      }
      sz = 0;
      for(int i = indx; i < offset; ++i) sz += words[i].size();
      int wordsSize = offset - indx;
      int remain = maxWidth - (sz + wordsSize - 1);
      int sps = wordsSize - 1;
      if(wordsSize == 1) {
        line = words[indx] + " " + string(remain, ' ');
      } else {
        if(offset >= words.size()) {
          // last line case
          for(int i = indx; i < offset; ++i) {
            line += words[i] + " ";
          }
          line += string(remain, ' ');
        } else {
          for(int i = indx; i < offset; ++i) {
            line += words[i] + " ";
            if(sps == 0) break;
            int num = remain % sps == 0 ? remain / sps : remain / sps + 1;
            line += string(num, ' ');
            remain -= num;
            sps -= 1;
          }
        }
      }
      lines.push_back(line.substr(0, line.size()-1));
      indx = offset;
    }
    return lines;
  }
};
