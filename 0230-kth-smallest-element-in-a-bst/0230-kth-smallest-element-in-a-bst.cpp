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
    void inordertraversal(TreeNode* root,vector<int>& temp){
        if(root==NULL){
            return;
        }
        inordertraversal(root->left,temp);
        temp.push_back(root->val);
        inordertraversal(root->right,temp);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        inordertraversal(root,ans);
        return ans[k-1];
    }
};