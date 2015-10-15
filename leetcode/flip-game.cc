class Solution {

 public:
  vector<string> generatePossibleNextMoves(string s) {
    vector<string> moves;
    if(s.size() == 0) return moves;
    for(int i = 0; i < s.size() - 1; ++i) {
      if(s[i] == '+' && s[i+1] == '+') {
        string tmp = s; tmp[i] = '-'; tmp[i+1] = '-'; moves.push_back(tmp);
      }
    }
    return moves;
  }
};
