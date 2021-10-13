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
    ListNode* swapPairs(ListNode* head) {
        ListNode* prev = new ListNode(-1, head);
        if(!head || !head->next)
            return head;
        ListNode* it = prev;
        while(it->next && it->next->next){
            ListNode* l = it->next;
            ListNode* r = it->next->next;
            it->next = r;
            l->next = r->next;
            r->next = l;
            it = l;
        }
        return prev->next;
    }
};