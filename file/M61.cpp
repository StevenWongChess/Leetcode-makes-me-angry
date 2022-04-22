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
        ListNode* prev = new ListNode(-1, head);
        ListNode* it = prev;
        int n = 0;
        while(it->next){
            n++;
            it = it->next;
        }
        if(n <= 1){
            return head;
        }
        k %= n;
        if(k == 0){
            return head;
        }
        ListNode* mid = prev; 
        for(int i = 0; i < n - k; i++){
            mid = mid->next;
        }
        ListNode* ans = mid->next;
        mid->next = nullptr;
        it->next = head;
        return ans;
    }
};