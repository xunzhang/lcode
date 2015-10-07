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
    ListNode *it = head;
    if(it == NULL) return head;
    while(it->next) {
      if(it->next->val == it->val) {
        ListNode *save = it->next;
        it->next = it->next->next;
        delete save;
      } else {
        it = it->next;
      }
    }
    return head;
  }
};
