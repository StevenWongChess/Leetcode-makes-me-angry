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
        ListNode* dummy = new ListNode(0, head), *it = dummy;
        for(int i = 0; i < left - 1; ++i){
            it = it->next;
        }

        ListNode* a = it;
        it = it->next;
        ListNode* b = it;

        ListNode* beforehand = nullptr;
        for(int i = 0; i < right - left + 1; ++i){
            if(i == right - left){
                a->next = it;
            }
            ListNode* tmp = it->next;
            it->next = beforehand;
            beforehand = it;
            it = tmp;
        }
        b->next = it;

        return dummy->next;
    }
};