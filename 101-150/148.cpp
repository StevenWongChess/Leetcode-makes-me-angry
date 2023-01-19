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
    ListNode* merge(ListNode* a, ListNode*b){
        ListNode* prev = new ListNode, *it = prev;
        while(a && b){
            if(a->val <= b->val){
                it->next = a;
                a = a->next;
            }
            else{
                it->next = b;
                b = b->next;
            }
            it = it->next;
        }
        it->next = a ? a : b;
        return prev->next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* tmp = slow->next;
        slow->next = nullptr;
        return merge(sortList(head), sortList(tmp));
    }
};