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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* prev = new ListNode(-1);
        ListNode* it = prev;
        while(l1 || l2){
            if(!l1){
                it->next = l2;
                break;
            }
            else if(!l2){
                it->next = l1;
                break;
            }
            else{
                if(l1->val <= l2->val){
                    it->next = new ListNode(l1->val);
                    it = it->next;
                    l1 = l1->next;
                }
                else{
                    it->next = new ListNode(l2->val);
                    it = it->next;
                    l2 = l2->next;
                }
            }
        }
        return prev->next;
    }
};