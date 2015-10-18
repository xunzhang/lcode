/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */

class Solution {
 public:
  /**
   * @param hashTable: A list of The first node of linked list
   * @return: A list of The first node of linked list which have
   * twice size
   */    
  vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
    // write your code here
    int sz = hashTable.size() * 2;
    vector<ListNode*> newHashTable(sz, NULL);
    vector<ListNode*> tail(sz, NULL);
    for(auto & list : hashTable) {
      ListNode *it = list;
      while(it) { ListNode *tmp = it->next;
        int indx = (it->val % sz + sz) % sz;
        ListNode *nd = new ListNode(it->val);
        if(newHashTable[indx] == NULL) {
          newHashTable[indx] = nd;
          tail[indx] = nd;
        } else {
          tail[indx]->next = nd;
          tail[indx] = nd;
        }
        delete it;
        it = tmp;
      }
    }
    return newHashTable;
  }
};
