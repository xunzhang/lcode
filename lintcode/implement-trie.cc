/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */
class TrieNode {
 public:
  // Initialize your data structure here.
  TrieNode() {
    neighbors.resize(26, NULL);
    isLeaf = false;
  }
  vector<TrieNode*> neighbors;
  bool isLeaf;
};

class Trie {
 public:
  Trie() {
    root = new TrieNode();
  }

  // Inserts a word into the trie.
  void insert(string word) {
    TrieNode* it = root;
    for(auto & ch : word) {
      if(it->neighbors[ch-'a'] == NULL) {
        it->neighbors[ch-'a'] = new TrieNode();
      }
      it = it->neighbors[ch-'a'];
    }
    it->isLeaf = true;
  }

  // Returns if the word is in the trie.
  bool search(string word) {
    TrieNode* it = root;
    for(auto & ch : word) {
      if(it->neighbors[ch - 'a'] != NULL) it = it->neighbors[ch - 'a'];
      else return false;
    }
    return it->isLeaf;
  }

  // Returns if there is any word in the trie
  // that starts with the given prefix.
  bool startsWith(string prefix) {
    TrieNode* it = root;
    for(auto & ch : prefix) {
      if(it->neighbors[ch - 'a'] != NULL) it = it->neighbors[ch - 'a'];
      else return false;
    }
    return true;
  }

 private:
  TrieNode* root;
};

