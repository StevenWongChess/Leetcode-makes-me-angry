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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev = new ListNode(-1, head);
        ListNode* it = prev;
        for(int i = 0; i < left - 1; i++){
            it = it->next;
        }
        ListNode* start = it;
        ListNode* tail = start->next;
        it = it->next;
        ListNode* before = nullptr;
        ListNode* after = nullptr;
        for(int i = left; i <= right; i++){
            after = it->next;
            it->next = before;
            before = it;
            if(i < right)
                it = after;
        }
        start->next = it;
        tail->next = after;
        return prev->next;
    };
};