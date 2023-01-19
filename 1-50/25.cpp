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
    void reverseK(ListNode* prev, ListNode* start, ListNode* end, int k){
        ListNode* nextprev = start, *nexthead = end->next;
        ListNode* it = start, *beforehand = nexthead;
        for(int i = 0; i < k; ++i){
            ListNode* tmp = it->next;
            it->next = beforehand;
            beforehand = it;
            it = tmp;
        }
        prev->next = end;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        auto prev = dummy;
        
        while(head){
            ListNode* end = prev;
            for(int i = 0; i < k; ++i){
                end = end->next;
                if(!end){
                    return dummy->next;
                }
            }
            reverseK(prev, head, end, k);
            prev = head; head = head->next;
        }
        
        return dummy->next;
    }
};