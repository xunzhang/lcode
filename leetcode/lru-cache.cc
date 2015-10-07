class LRUCache{

 public:
  LRUCache(int capacity) {
    sz = capacity;
    head = new Node(0, 0);
    tail = new Node(0, 0);
    head->right = tail;
    tail->left = head;
  }

  ~LRUCache() {
    Node *it = head;
    while(it) {
      Node *tmp = it->right;
      delete it;
      it = tmp;
    }
  }

  int get(int key) {
    if(M.count(key)) {
      detach(M[key]);
      attach(M[key]);
      return M[key]->value;
    }
    return -1;
  }

  void set(int key, int value) {
    if(!M.count(key)) {
      Node *newNode = new Node(key, value);
      if(M.size() == sz) {
        Node *tmp = tail->left;
        detach(tmp);
        M.erase(tmp->key);
        delete tmp;
      }
      attach(newNode);
      M[key] = newNode;
    } else {
      detach(M[key]);
      attach(M[key]);
      M[key]->value = value;
    }
  }

 private:
  class Node {
   public:
    int key = 0, value = 0;
    Node *left = NULL, *right = NULL;
    Node(int k, int v) : key(k), value(v) {}
  };

 private:
  // not only occur in tail
  void detach(Node *nd) {
    nd->left->right = nd->right;
    nd->right->left = nd->left;
  }

  // only occur in head
  void attach(Node *nd) {
    nd->left = head;
    nd->right = head->right;
    head->right->left = nd;
    head->right = nd;
  }

 private:
  int sz = 0;
  Node *head, *tail;
  unordered_map<int, Node*> M;
};
