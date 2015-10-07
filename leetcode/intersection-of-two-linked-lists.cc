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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == NULL || headB == NULL) return NULL;
    int cntA = 0, cntB = 0;
    ListNode *itA = headA, *itB = headB;
    while(itA->next) { itA = itA->next; cntA ++; }
    while(itB->next) { itB = itB->next; cntB ++; }
    if(itA != itB) return NULL;
    itA = headA; itB = headB;
    if(cntA < cntB) {
      for(int i = 0; i < cntB - cntA; ++i) { itB = itB->next; }
    } else {
      for(int i = 0; i < cntA - cntB; ++i) { itA = itA->next; }
    }
    while(itA != itB) {
      itA = itA->next;
      itB = itB->next;
    }
    return itA;
  }
};
