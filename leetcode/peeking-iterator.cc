// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
  struct Data;
  Data* data;
 public:
  Iterator(const vector<int>& nums);
  Iterator(const Iterator& iter);
  virtual ~Iterator();
  // Returns the next element in the iteration.
  int next();
  // Returns true if the iteration has more elements.
  bool hasNext() const;
};

class PeekingIterator : public Iterator {

 public:
  PeekingIterator(const vector<int>& nums) : Iterator(nums) {
    // Initialize any member here.
    // **DO NOT** save a copy of nums and manipulate it directly.
    // You should only use the Iterator interface methods.
    cache();
  }

  // Returns the next element in the iteration without advancing the
  // iterator.
  int peek() {
    return peekElem;
  }

  // hasNext() and next() should behave the same as in the Iterator
  // interface.
  // Override them if needed.
  int next() {
    int v = peekElem;
    cache();
    return v;
  }

  bool hasNext() const {
    return hasPeeked;
  }

 private:
  void cache() {
    if(Iterator::hasNext()) {
      peekElem = Iterator::next();
      hasPeeked = true;
    } else {
      hasPeeked = false;
    }
  }

 private:
  int peekElem;
  bool hasPeeked = false;
};
