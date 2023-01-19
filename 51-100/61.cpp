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
        if(!head)
            return head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* tail = dummy;
        int n = 0;
        while(tail->next){
            ++n;
            tail = tail->next; // it finally becomes the end of the linked list
        }
        k %= n;
        if(k == 0){
            return head;
        }

        ListNode* a = dummy;
        for(int i = 0; i < n - k; ++i){
            a = a->next;
        }
        ListNode* b = a->next;
        a->next = nullptr;
        tail->next = head;
        dummy->next = b;

        return dummy->next;
    }
};