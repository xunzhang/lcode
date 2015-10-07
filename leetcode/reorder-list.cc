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
  ListNode* reverseList(ListNode* head) {
    ListNode *it = head, *prev = NULL;
    while(it) {
      ListNode *tmp = it->next;
      it->next = prev;
      prev = it;
      it = tmp;
    }
    return prev;
  }

  void reorderList(ListNode* head) {
    if(head == NULL || head->next == NULL) return;
    ListNode *it1 = head, *it2 = head, *prev = NULL;
    while(it2 && it2->next) {
      prev = it1;
      it1 = it1->next;
      it2 = it2->next->next;
    }
    prev->next = NULL;
    it2 = reverseList(it1);
    it1 = head;
    // merge
    while(it1) {
      ListNode *tmp1 = it1->next;
      ListNode *tmp2 = it2->next;
      it1->next = it2;
      if(tmp1) it2->next = tmp1;
      it1 = tmp1;
      it2 = tmp2;
    }
  }
};
