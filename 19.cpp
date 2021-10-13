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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* help = new ListNode(-1, head);
        ListNode* fast = help;
        ListNode* slow = help;
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* victim = slow->next; 
        slow->next = slow->next->next;
        delete(victim);
        return help->next;
    }
};