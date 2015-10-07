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
  ListNode* swapPairs(ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    ListNode *tmp = head->next->next;
    ListNode *r = head->next;
    head->next->next = head;
    head->next = swapPairs(tmp);
    return r;
  }
};
