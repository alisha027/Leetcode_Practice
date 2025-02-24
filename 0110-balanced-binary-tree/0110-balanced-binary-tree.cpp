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
    int count(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int a  = count(root->left);
        int b = count(root->right);
        if(a==-1 || b==-1 || abs(a-b)>1){
            return -1;
        }
        return max(a,b)+1;
    }
    bool isBalanced(TreeNode* root) {
        int c = count(root);
        if(c==-1){
            return false;
        }else{
            return true;
        }
    }
};