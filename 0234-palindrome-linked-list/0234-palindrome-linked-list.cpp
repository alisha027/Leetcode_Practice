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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next == NULL){
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* curr = head;
        ListNode* prev = NULL, *next;
        while(curr != slow){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if(fast!=NULL){
            curr = curr->next;
        }
        while(prev != NULL){
            if(prev->val != curr->val){
                return false;
            }
            curr = curr->next;
            prev = prev->next;
        }
        return true;
    }
};