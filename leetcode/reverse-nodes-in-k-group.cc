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

  ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == NULL) return NULL;
    ListNode *it = head;
    for(int i = 0; it && i < k - 1; ++i) it = it->next;
    if(it == NULL) return head;
    ListNode *tmp = it->next, *save = head;
    it->next = NULL;
    head = reverseList(head);
    save->next = reverseKGroup(tmp, k);
    return head;
  }
};
