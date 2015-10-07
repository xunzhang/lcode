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
  // O(n^2)
  ListNode* insertionSortList(ListNode* head) {
    ListNode *newHead = NULL;
    ListNode *it = head;
    for(ListNode *it = head; it != NULL;) {
      if(newHead == NULL) {
        newHead = it;
        it = it->next;
        newHead->next = NULL;
      } else {
        ListNode *prev = NULL, *curr = newHead, *tmp = it->next;
        while(curr && curr->val < it->val) {
          prev = curr;
          curr = curr->next;
        }
        if(prev == NULL) {
          newHead = it;
        } else {
          prev->next = it;
        }
        it->next = curr;
        it = tmp;
      }
    }
    return newHead;
  }
};
