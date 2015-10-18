class Solution {
 public:
  /**
   * @param key: A String you should hash
   * @param HASH_SIZE: An integer
   * @return an integer
   */
  int hashCode(string key,int HASH_SIZE) {
    // write your code here
    //assert(HASH_SIZE != 33);
    uint64_t hash = 0;
    for(int i = 0; i < key.size(); ++i) {
      hash = 33 * hash + key[i];
      hash = hash % HASH_SIZE;
    }
    return static_cast<int>(hash % HASH_SIZE);
  }
};
