class ValidWordAbbr {

 public:
  string toAbbr(string word) {
    if(word.size() <= 2) return word;
    else return word[0] + to_string(word.size() - 2) + word.back();
  }

  ValidWordAbbr(vector<string> &dictionary) {
    for(auto & word : dictionary) {
      abbrMap[toAbbr(word)].push_back(word);
    }
  }

  bool isUnique(string word) {
    string r = toAbbr(word);
    if(!abbrMap.count(r)) return true;
    else if(abbrMap[r].size() == 1 && abbrMap[r][0] == word) return true;
    else return false;
  }

 private:
  unordered_map<string, vector<string>> abbrMap;
};

// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
