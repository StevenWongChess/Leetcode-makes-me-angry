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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* prev = new ListNode(-1, head);
        ListNode* a = head, *b = head->next;
        while(b){
            if(a->val <= b->val){
                a = a->next;
                b = b->next;
            }
            else{
                ListNode* it = prev;
                while(it->next && it->next->val < b->val){
                    it = it->next;
                }
                ListNode* tmp = it->next, *tmp2 = b->next;
                it->next = b;
                b->next = tmp;
                a->next = tmp2;
                b = tmp2;
            }
        }
        return prev->next;
    }
};