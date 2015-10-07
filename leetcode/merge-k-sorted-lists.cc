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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    ListNode *head = NULL;
    if(l1->val < l2->val) {
      head = l1;
      l1 = l1->next;
    } else {
      head = l2;
      l2 = l2->next;
    }
    ListNode *it = head;
    while(l1 != NULL && l2 != NULL) {
      if(l1->val < l2->val) { 
        it->next = l1;
        l1 = l1->next;
      } else {
        it->next = l2;
        l2 = l2->next;
      }
      it = it->next;
    }
    if(l1 != NULL) it->next = l1;
    if(l2 != NULL) it->next = l2;
    return head;
  }
  // O(nklogk)
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size() == 0) return NULL;
    ListNode *head = NULL;
    vector<ListNode*> data(lists);
    while(data.size() > 1) {
      int s = 0, e = data.size() - 1;
      while(s < e) {
        data[s] = mergeTwoLists(data[s], data[e]);
        data.pop_back();
        s ++;
        e --;
      }
    }
    return data[0];
  }
};
