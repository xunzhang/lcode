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
  ListNode* reverseList_it(ListNode* head) {
    ListNode *it = head, *prev = NULL;
    while(it) {
      ListNode *tmp = it->next;
      it->next = prev;
      prev = it;
      it = tmp;
    }
    return prev;
  }
  ListNode* reverseList(ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    ListNode *tmp = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return tmp;
  }
};
