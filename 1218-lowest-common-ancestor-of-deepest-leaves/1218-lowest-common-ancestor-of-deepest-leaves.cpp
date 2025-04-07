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
//  we have a question that we have to find lowest common ancestor of deepest node. so we have to first find the deepest node and then we have to store path of all deepest node in adjacency matrix then we have to compare all adjacency matrix if at a point they mismatch then the previous node will be the answer code it in c++ in a function
class Solution {
private:
    pair<TreeNode*,int> getLCADeepestLeaves(TreeNode* root){
        if(root == NULL){
            return {NULL,0};
        }
        auto left = getLCADeepestLeaves(root->left);
        auto right = getLCADeepestLeaves(root->right);

        if(left.second == right.second){
            return {root,1+left.second};
        }
        if(left.second > right.second){
            return {left.first, 1 + left.second};
        }
        return {right.first, 1 + right.second};
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto res = getLCADeepestLeaves(root);
        return res.first;
    }
};