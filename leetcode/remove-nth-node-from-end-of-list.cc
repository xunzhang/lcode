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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *it1 = head, *it2 = head;
    int i = 0;
    for(; i < n && it2->next; ++i) it2 = it2->next;
    if(i < n) {
      head = head->next;
      delete it1;
      return head;
    }
    while(it2->next) { it1 = it1->next; it2 = it2->next; }
    ListNode *save = it1->next;
    it1->next = it1->next->next;
    delete save;
    return head;
  }
};
