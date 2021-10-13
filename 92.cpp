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
        // if(left == right)
        //     return head;
        ListNode* prev = new ListNode(-1, head);
        ListNode* it = prev;
        for(int i = 1; i < left; i++)
            it = it->next;
        ListNode* start = it;

        ListNode* before = nullptr;
        ListNode* tmp = nullptr;
        it = it->next;
        for(int i = 1; i <= right - left + 1; i++){
            tmp = it->next;
            it->next = before;
            before = it;
            if(i < right - left + 1)
                it = tmp;
        }
        ListNode* tail = start->next;
        start->next = it;
        tail->next = tmp;
        return prev->next;
    };
};