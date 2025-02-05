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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> temp;
        queue<TreeNode*> q;
        if(root==NULL){
            return temp;
        }
        q.push(root);
        while(!q.empty()){
            vector<int> temp2;
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* newnode = q.front();
                q.pop();
                temp2.push_back(newnode->val);
                if(newnode->left!=NULL){
                    q.push(newnode->left);
                }
                if(newnode->right!=NULL){
                    q.push(newnode->right);
                }
            }
            temp.push_back(temp2);   
        }
        return temp;
    }
};
// vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> result;
//         if(!root){
//             return result;
//         }
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()){
//             vector<int> temp;
//             int size = q.size();
//             for(int i=0;i<size;i++){
//                 TreeNode* newnode = q.front();
//                 q.pop();
//                 temp.push_back(newnode->val);
//                 if(newnode->left){
//                     q.push(newnode->left);
//                 }
//                 if(newnode->right){
//                     q.push(newnode->right);
//                 }
//             }
//             result.push_back(temp);
//         } 
//         return result;
// }
// };