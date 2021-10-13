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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* prev = new ListNode(-1, head);
        ListNode* it = prev;
        while(it->next){
            ListNode* cmp = prev;
            int moved = false;
            while(cmp->next && cmp->next != it->next){
                if(cmp->next->val >= it->next->val){
                    moved = true;
                    auto tmp = it->next;
                    it->next = it->next->next;
                    auto tmp2 = cmp->next;
                    cmp->next =tmp;
                    tmp->next = tmp2;
                    break;
                }
                cmp = cmp->next;
            }
            if(!moved)
                it = it->next;
        }
        return prev->next;
    }
};