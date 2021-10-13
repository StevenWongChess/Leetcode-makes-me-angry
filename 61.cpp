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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* prev = new ListNode(-1, head);
        ListNode* it = prev;
        int length = 0;
        while(it->next){
            length++;
            it = it->next;
        }
        if(length == 0)
            return nullptr;
        ListNode* end = it;
        int act = k % length;
        if(act == 0)
            return head;
        it = prev;
        for(int i = 0; i < length - act; i++){
            it = it->next;
        }
        ListNode* tmp = prev->next;
        prev->next = it->next;
        end->next = tmp;
        it->next = nullptr;
        return prev->next;
    }
};