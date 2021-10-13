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
    ListNode* partition(ListNode* head, int x) {
        ListNode* prev = new ListNode(-1, nullptr);
        ListNode* left = prev; 
        ListNode* right = new ListNode(-1, nullptr);
        ListNode* half = right;
        ListNode* it = head;
        while(it){
            if(it->val < x){
                left->next = it; left = left->next;
            }
            else{
                right->next = it; right = right->next;
            }
            it = it->next;
        }
        right->next = nullptr;
        left->next = half->next;
        return prev->next;
    }
};