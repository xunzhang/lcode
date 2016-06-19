/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
 public:

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if(root == NULL) return "";
    string str;
    dump(root, str);
    return str;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if(data.size() == 0) return NULL;
    TreeNode *p;
    load(p, data);
    return p;
  }

 private:
  void dump(TreeNode *p, string & str) {
    if(p == NULL) { str += '#'; return; }
    str += '|' + to_string(p->val) + '|';
    dump(p->left, str);
    dump(p->right, str);
  }

  void load(TreeNode *&p, string & str) {
    if(str.size() == 0) return ;
    if(str[0] == '#') { str = str.substr(1, str.size() - 1); return; }
    int indx = 1; while(indx < str.size() && str[indx] != '|') indx ++;
    p = new TreeNode(stoi(str.substr(1, indx - 1)));
    str = str.substr(indx + 1, str.size() - indx - 1);
    load(p->left, str);
    load(p->right, str);
  }

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
