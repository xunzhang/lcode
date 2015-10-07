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
  ListNode* partition(ListNode* head, int x) {
    ListNode *it = head;
    ListNode *lhead = NULL, *lprev = NULL;
    ListNode *rhead = NULL, *rprev = NULL;
    while(it) {
      if(it->val < x) {
        if(lprev == NULL) {
          lhead = it;
        } else {
          lprev->next = it;
        }
        lprev = it;
      } else {
        if(rprev == NULL) {
          rhead = it;
        } else {
          rprev->next = it;
        }
        rprev = it;
      }
      it = it->next;
    }
    if(rprev) rprev->next = NULL;
    if(lprev) lprev->next = rhead;
    if(lhead == NULL) return rhead;
    return lhead;
  }
};
