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

    // int levelOrder(TreeNode* root,int count,vector<int> temp){
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     q.push(NULL);
    //     while(!q.empty()){
    //         TreeNode* f = q.front();
    //         q.pop();
    //         if(f==NULL){
    //             cout << endl;
    //             count++;

    //             if(!q.empty()){
    //                 q.push(NULL);
    //             }
    //         }else{
    //             temp.push_back(f->val);
    //             if(f->left!=NULL){
    //                 q.push(f->left);
    //             }
    //             if(f->right!=NULL){
    //                 q.push(f->right);
    //             }
    //         }
    //     }
    //     return count;
    // }

    int countheight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int a = countheight(root->left);
        int b = countheight(root->right);
        return (1+max(a,b));
    }
    int maxDepth(TreeNode* root) {
        int count = countheight(root);
        return count;
    }
};