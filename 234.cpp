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
        if(!head || !head->next)
            return true;
        ListNode* prev = new ListNode(-1, head);
        ListNode* slow = prev;
        ListNode* fast = prev;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* it = prev->next;
        ListNode* former = nullptr;
        ListNode* before = prev->next;
        // ListNode* after = slow->next;
        ListNode* cmp = (slow->next);
        while(it != cmp){
            ListNode* tmp = it;
            it = it->next;
            tmp->next = former;
            former = tmp;
        }    
        prev->next = slow;
        before->next = it;
        ListNode* first_half = slow;
        ListNode* second_half = fast->next ? it->next : it;
        // we need to case by case based on odd or even size
        //reverse the second half
        while(first_half && second_half){
            if(first_half->val != second_half->val)
                return false;
            first_half = first_half->next;
            second_half = second_half->next;
        }
        return true;
    }
};