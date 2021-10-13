/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* prev = new ListNode(-1, head);
        ListNode* slow = prev;
        ListNode* fast = prev;
        bool flag = false;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                flag = true;
                break;
            }
        }
        if(!flag)
            return nullptr;
        ListNode* it = prev;
        while(it != fast){
            it = it->next;
            fast = fast->next;
        }
        return it;
    }
};