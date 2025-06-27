/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        vector<ListNode*> nodes;
        ListNode* curr = head;
        while (curr) {
            nodes.push_back(curr);
            curr = curr->next;
        }

        sort(nodes.begin(), nodes.end(), [](ListNode* a, ListNode* b) {
            return a->val < b->val;
        });

        for (int i = 0; i < nodes.size() - 1; ++i)
            nodes[i]->next = nodes[i + 1];
        nodes.back()->next = nullptr;

        return nodes[0];
    }
};
