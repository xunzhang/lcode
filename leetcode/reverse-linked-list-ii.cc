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

  ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode *it1 = head, *it2 = head;
    for(int i = 1; i < m - 1; ++i) it1 = it1->next;
    for(int i = 1; i < n; ++i) it2 = it2->next;
    ListNode *tmp = it2->next;
    ListNode *tmp2 = it1->next;
    it2->next = NULL;
    if(m == 1) {
      tmp2 = head;
      head = reverseList(head);
    } else {
      it1->next = reverseList(tmp2);
    }
    tmp2->next = tmp;
    return head;
  }
};
