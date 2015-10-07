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

  bool isPalindrome(ListNode* head) {
    if(head == NULL) return true;
    ListNode *it1 = head, *it2 = head;
    while(it2 && it2->next) {
      it1 = it1->next;
      it2 = it2->next->next;
    }
    ListNode *tmp = NULL;
    if(it2) {
      tmp = it1->next;
    } else {
      tmp = it1;
    }
    it2 = reverseList(tmp);
    it1 = head;
    while(it2) {
      if(it1->val != it2->val) return false;
      it1 = it1->next;
      it2 = it2->next;
    }
    return true;
  }
};
