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

    void findNodes(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& mapparents, 
                   unordered_set<TreeNode*>& visited, int k, vector<int>& result) {
        if (!node || visited.count(node)) {
            return;
        }
        visited.insert(node);
        if (k == 0) {
            result.push_back(node->val);
            return;
        }
        
        findNodes(node->left, mapparents, visited, k - 1, result);
        findNodes(node->right, mapparents, visited, k - 1, result);
        findNodes(mapparents[node], mapparents, visited, k - 1, result);
    }

    TreeNode* findtargetnode(TreeNode* root, TreeNode* target) {
        if (root == NULL) {
            return NULL;
        }
        
        if (root->val == target->val) {
            return root;
        }
        TreeNode* searchleft = findtargetnode(root->left, target);
        if (searchleft) {
            return searchleft;
        }
        return findtargetnode(root->right, target);
    }

    void storeparents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mapparents, TreeNode* parent = NULL) {
        if (root == NULL) {
            return;
        }
        mapparents[root] = parent;
        storeparents(root->left, mapparents, root);
        storeparents(root->right, mapparents, root);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mapparents;
        unordered_set<TreeNode*> visited;
        vector<int> result;

        storeparents(root, mapparents);
        TreeNode* targetNode = findtargetnode(root, target);
        findNodes(targetNode, mapparents, visited, k, result);
        return result;
    }
};
