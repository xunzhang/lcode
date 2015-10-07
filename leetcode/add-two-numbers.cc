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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *h = new ListNode(0), *it = h;
    int carry = 0;
    while(l1 || l2) {
      int v = carry;
      if(l1) { v += l1->val; l1 = l1->next; }
      if(l2) { v += l2->val; l2 = l2->next; }
      ListNode *new_node = new ListNode(v % 10);
      carry = v / 10;
      it->next = new_node;
      it = new_node;
    }
    if(carry) it->next = new ListNode(carry);
    ListNode *tmp = h;
    h = h->next;
    delete tmp;
    return h;
  }
};
