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
    ListNode* reverseList(ListNode* head) {
        ListNode* it = head;
        ListNode* forward = nullptr;
        while(it){
            ListNode* current = it;
            it = it->next;
            current->next = forward;
            forward = current;
        }
        return forward;
    }
};