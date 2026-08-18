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
    void reorderList(ListNode* head) {
        if(!(!head || !head->next || !head->next->next)){
            ListNode* slow = head->next;
            ListNode* fast = head->next->next;
            while(fast && fast->next){
                slow = slow->next;
                fast = fast->next->next;
            }
            ListNode* curr = slow->next;
            ListNode* prev = slow;
            ListNode* mid = slow;
            while(curr){
                ListNode *temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            curr = head;
            while(prev != mid){
                ListNode *temp = curr->next;
                curr->next = prev;
                prev = prev->next;
                curr->next->next = temp;
                curr = temp;
            }
            prev->next = NULL;
        }
    }
};
