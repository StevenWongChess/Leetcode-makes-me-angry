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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = new ListNode(0, head);
        ListNode* ans = prev;
        ListNode* it = head;
        while(it){
            if(it->val == val){
                it = it->next;
                prev->next = it;
            }
            else{
                prev = prev->next;
                it = it->next;
            }
        }
        ListNode* ret = ans->next;
        delete ans;
        return ret;
    }
};