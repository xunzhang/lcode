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
	ListNode* sortList(ListNode* head) {
	  if(head == NULL || head->next == NULL) return head;
	  ListNode *l1 = head, *l2 = head;
	  while(l2->next && l2->next->next) {
		l1 = l1->next;
		l2 = l2->next->next;
	  }
	  ListNode *mid = l1->next;
	  l1->next = NULL;
	  ListNode *hd = head;
	  hd = sortList(hd);
	  mid = sortList(mid);
	  return mergeTwoLists(hd, mid);
	}
};
