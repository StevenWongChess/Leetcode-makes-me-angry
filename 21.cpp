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
        ListNode* first = nullptr;
        ListNode* it = nullptr;
        while(l1 || l2){
            ListNode* choice;
            if(!l1)
                choice = l2;
            else if(!l2)
                choice = l1;
            else
                choice = l1->val >= l2->val ? l2 : l1;
            if(!first)
                first = it = choice;
            else{
                it->next = choice;
                it = it->next;
            }
            if(choice == l1)
                l1 = l1->next;
            else
                l2 = l2->next;
        }
        return first;
    }
};