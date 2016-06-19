class Solution {
 public:
  string getHint(string secret, string guess) {
    int As = 0, Bs = 0;
    unordered_map<int, int> D; // secret's digit -> number of wrong locations
    for(size_t i = 0; i < secret.size(); ++i) {
      if(secret[i] == guess[i]) {
        As += 1;
        continue;
      } else {
        D[secret[i]-'0'] += 1;
      }
    }
    for(size_t i = 0; i < guess.size(); ++i) {
      if(secret[i] == guess[i]) continue;
      else {
        auto it = D.find(guess[i] - '0');
        if(it == D.end()) continue;
        if(it->second == 0) continue;
        Bs += 1;
        it->second -= 1; 
      }
    }
    return to_string(As) + "A" + to_string(Bs) + "B";
  }
};
