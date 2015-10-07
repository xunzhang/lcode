/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

class Solution {
 public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    if(head == NULL) return NULL;
    RandomListNode *it = head;
    while(it) {
      RandomListNode *tmp = it->next;
      RandomListNode *node = new RandomListNode(it->label);
      it->next = node;
      node->next = tmp;
      it = tmp;
    }
    it = head;
    while(it) {
      if(it->random) {
        it->next->random = it->random->next;
      }
      it = it->next->next;
    }
    RandomListNode *newHead = head->next;
    it = head;
    while(it) {
      RandomListNode *tmp = it->next;
      it->next = tmp->next;
      if(tmp->next) tmp->next = tmp->next->next;
      it = it->next;
    }
    return newHead;
  }
};
