/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
  TreeNode* prev = nullptr;

  int inorder(TreeNode* root) {
    int ret_val = INT_MAX;
    if (root == nullptr) return ret_val;
    ret_val = min(ret_val, inorder(root->left));
    if (prev) {
      ret_val = min(ret_val, abs(prev->val - root->val));
    }
    prev = root;
    ret_val = min(ret_val, inorder(root->right));
    
    return ret_val;
  }

  int getMinimumDifference(TreeNode* root) {
    return inorder(root); 
  }
};