class Solution {

 public:
  string nextPermutation(string seq) {
    string r = seq;
    int i = r.size() - 2;
    while(i >= 0 && r[i] >= r[i+1]) --i;
    if(i == -1) {
      reverse(r.begin(), r.end());
      return r;
    }
    for(int k = r.size() - 1; k > i; --k) {
      if(r[k] > r[i]) {
        swap(r[k], r[i]);
        break;
      }
    }
    reverse(r.begin() + i + 1, r.end());
    return r;
  }

  vector<string> generatePalindromes(string s) {
    vector<string> result;
    unordered_set<char> SS;
    string prefix;
    for(auto & ch : s) {
      if(SS.count(ch)) {
        prefix.push_back(ch);
        SS.erase(ch);
      } else {
        SS.insert(ch);
      }
    }
    if(SS.size() > 1) return result;
    char mid;
    if(SS.size()) for(auto & ch : SS) mid = ch;
    sort(prefix.begin(), prefix.end());
    string it = prefix;
    while(1) {
      string palindrome = mid ? it + mid + string(it.rbegin(), it.rend()) : it + string(it.rbegin(), it.rend());
      result.push_back(palindrome);
      it = nextPermutation(it);
      if(it == prefix) break;
    }
    return result;
  }
};
