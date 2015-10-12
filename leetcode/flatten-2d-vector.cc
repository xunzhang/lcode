class Vector2D {

 public:
  Vector2D(vector<vector<int>>& vec2d) {
    for(auto & vec : vec2d) {
      if(vec.size() > 0) data.push_back(vec);
    }
    if(data.size() > 0) {
      x = 0; y = 0;
    } else {
      x = -1; y = -1;
    }
  }

  int next() {
    int v = data[x][y];
    if(y + 1 == data[x].size()) {
      x ++; y = 0;
      if(x == data.size()) x = -1;
    } else {
      y ++;
    }
    return v;
  }

  bool hasNext() {
    return x != -1;
  }

 private:
  vector<vector<int>> data;
  int x, y;
};



/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
