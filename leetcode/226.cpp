// 226. Invert Binary Tree

/* Approach 1 - Recursive solution */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        TreeNode *left = root->left, *right = root->right; 
        root->right = invertTree(left);
        root->left = invertTree(right);
        return root;
    }
};

/* Approach 2 - BFS solution */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* ptr = q.front();
            q.pop();
            swap(ptr->left, ptr->right);
            if (ptr->left) q.push(ptr->left);
            if (ptr->right) q.push(ptr->right);
        }

        return root;
    }
};