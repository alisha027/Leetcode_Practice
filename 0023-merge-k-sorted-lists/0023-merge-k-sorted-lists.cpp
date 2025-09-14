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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);
        for (auto node : lists) {
            if (node) minHeap.push(node);
        }
        ListNode dummy;
        ListNode* tail = &dummy;

        while (!minHeap.empty()) {
            ListNode* top = minHeap.top();
            minHeap.pop();

            tail->next = top;
            tail = tail->next;

            if (top->next) {
                minHeap.push(top->next);
            }
        }

        return dummy.next;
    }
};
