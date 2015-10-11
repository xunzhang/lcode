class Codec {

 public:
  // Encodes a list of strings to a single string.
  string encode(vector<string>& strs) {
    string s = "";
    for(auto & str : strs) s += to_string(static_cast<int>(str.size())) + '#' + str;
    return s;
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s) {
    vector<string> strs;
    int start = 0;
    while(start < s.size()) {
      int pos = s.find_first_of('#', start);
      int len = stoi(s.substr(start, pos - start));
      strs.push_back(s.substr(pos + 1, len));
      start = pos + len + 1;
    }
    return strs;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
