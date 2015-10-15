/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
 public:
  /**
   * This method will be invoked first, you should design your own
   * algorithm 
   * to serialize a binary tree which denote by a root node to a
   * string which
   * can be easily deserialized by your own "deserialize"
   * method later.
   */
  string serialize(TreeNode *root) {
    // write your code here
    if(root == NULL) return "";
    string str;
    dump_vlr(root, str);
    return str;
  }

  /**
   * This method will be invoked second, the argument data is what
   * exactly
   * you serialized at method "serialize", that means the
   * data is not given by
   * system, it's given by your own serialize method. So
   * the format of data is
   * designed by yourself, and deserialize it here
   * as you serialize it in 
   * "serialize" method.
   */
  TreeNode *deserialize(string data) {
    // write your code here
    if(data.size() == 0) return NULL;
    TreeNode *p;
    load_vlr(p, data);
    return p;
  }

 private:
  void dump_vlr(TreeNode *p, string & str) {
    if(p == NULL) { str.push_back('#'); return; }
    str.push_back(p->val + 'a');
    dump_vlr(p->left, str);
    dump_vlr(p->right, str);
  }

  void load_vlr(TreeNode *&p, string & str) {
    if(str.size() == 0) return;
    if(str[0] == '#') { str = str.substr(1, str.size() - 1); return; }
    p = new TreeNode(str[0] - 'a');
    str = str.substr(1, str.size() - 1);
    load_vlr(p->left, str);
    load_vlr(p->right, str);
  }
};
