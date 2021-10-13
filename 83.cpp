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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return nullptr;
        ListNode* prev = head;
        ListNode* it = head->next;
        while(it){
            if(it->val != prev->val){
                it = it->next;
                prev = prev->next;
            }
            else{
                auto victim = it;
                prev->next = it->next;
                it = it->next;
                delete victim;
            }
        }
        return head;
    }
};