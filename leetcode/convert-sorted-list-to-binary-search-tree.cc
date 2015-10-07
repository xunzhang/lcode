/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
 public:
  TreeNode* sortedListToBST(ListNode* head) {
    if(head == NULL) return NULL;
    ListNode *mid = head, *it2 = head, *prev = NULL;
    while(it2 && it2->next) {
      prev = mid;
      mid = mid->next;
      it2 = it2->next->next;
    }
    TreeNode *node = new TreeNode(mid->val);
    if(prev == NULL) {
      node->left = NULL;
    } else {
      prev->next = NULL;
      node->left = sortedListToBST(head);
    }
    node->right = sortedListToBST(mid->next);
    return node;
  }
};
