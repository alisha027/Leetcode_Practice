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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        
        // If no left child, go right
        if (!root->left) return 1 + minDepth(root->right);
        
        // If no right child, go left
        if (!root->right) return 1 + minDepth(root->left);
        
        // Both children exist, take minimum
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
