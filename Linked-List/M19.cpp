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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = new ListNode(-1, head);
        ListNode* it = prev;
        ListNode* tail = prev;
        for(int i = 0; i < n + 1; i++){
            tail = tail->next;
        }
        while(tail){
            it = it->next;
            tail = tail->next;
        }
        it->next = it->next->next;
        return prev->next;
    }
};