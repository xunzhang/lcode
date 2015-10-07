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
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    if(nums.size() == 0) return NULL;
    int mid = nums.size() / 2;
    TreeNode *node = new TreeNode(nums[mid]);
    vector<int> leftNums, rightNums;
    for(int i = 0; i < mid; ++i) leftNums.push_back(nums[i]);
    for(int i = mid + 1; i < nums.size(); ++i) rightNums.push_back(nums[i]);
    node->left = sortedArrayToBST(leftNums);
    node->right = sortedArrayToBST(rightNums);
    return node;
  }
};
