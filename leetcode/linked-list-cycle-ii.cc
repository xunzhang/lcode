/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *it1 = head, *it2 = head;
    while(it2 && it2->next) {
      it1 = it1->next;
      it2 = it2->next->next;
      if(it1 == it2) break;
    }
    if(it2 == NULL || it2->next == NULL) return NULL;
    it1 = head;
    while(it1 != it2) {
      it1 = it1->next;
      it2 = it2->next;
    }
    return it1;
  }
};
