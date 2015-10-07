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
  ListNode* removeElements(ListNode* head, int val) {
    ListNode *it = head, *prev = NULL;
    while(it) {
      if(it->val == val) {
        if(prev) {
          prev->next = it->next;
        } else {
          head = it->next;
        }
        ListNode *tmp = it;
        it = it->next;
        delete tmp;
      } else {
        prev = it;
        it = it->next;
      }
    }
    return head;
  }
};
