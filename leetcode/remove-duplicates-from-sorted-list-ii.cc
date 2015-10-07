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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode *prev = NULL, *it = head;
    while(it) {
      if(it->next == NULL || it->next->val != it->val) {
        if(prev == NULL) {
          prev = it;
          head = it;
        } else {
          prev->next = it;
          prev = it;
        }
        it = it->next;
      } else {
        while(it->next && it->next->val == it->val) it = it->next;
        it = it->next;
      }
    }
    if(prev == NULL) {
      prev = NULL;
      head = NULL;
    } else {
      prev->next = NULL;
    }
    return head;
  }
};
