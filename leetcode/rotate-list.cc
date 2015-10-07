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
  ListNode* rotateRight(ListNode* head, int k) {
    if(k == 0 || head == NULL) return head;
    ListNode *it1 = head, *it2 = head;
    int l = 0;
    while(it2) { it2 = it2->next; l++; }
    it2 = head;
    for(int i = 0; i < k % l; ++i) { 
      it2 = it2->next;
      if(it2 == NULL) return head;
    }
    while(it2->next) { it1 = it1->next; it2 = it2->next; }
    if(it1 == it2) return head;
    it2->next = head;
    head = it1->next;
    it1->next = NULL;
    return head;
  }
};
