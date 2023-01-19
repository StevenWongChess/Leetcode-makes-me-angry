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
        ListNode* before = new ListNode(-1, head);
        ListNode* slow = before;
        ListNode* fast = before;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = fast->next ? slow->next : slow;
        // reverse second_half;
        ListNode* it = mid->next;
        ListNode* prev = nullptr;
        ListNode* second_half = nullptr;
        while(it){
            ListNode* tmp = it->next;
            if(!tmp)
                second_half = it;
            it->next = prev;
            prev = it;
            it = tmp;
        }
        // mid->next = second_half;
        mid->next =  nullptr;
        // merge 
        it = before->next;
        while(second_half){
            ListNode* t1 = it->next; ListNode* t2 = second_half->next; 
            it->next = second_half;
            second_half->next = t1;
            it = t1;
            second_half = t2;
        }
        if(it)
            it->next = nullptr;
    }
};