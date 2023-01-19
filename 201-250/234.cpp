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
    void reverse(ListNode* c, ListNode* d, int count){
        ListNode* last = nullptr, *it = c;
        for(int i = 0; i < count; ++i){
            ListNode* tmp = it->next;
            it->next = last;
            last = it;
            it = tmp;
        }
    }

    bool isPalindrome(ListNode* head) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode *b, *c, *d;
        ListNode* it = dummy;
        int n = 0;    
        while(it->next){
            it = it->next;
            ++n;
        }
        d = it;

        it = dummy;
        for(int i = 0; i < n / 2; ++i){
            it = it->next;
        }
        b = it; c = it->next; b->next = nullptr;

        reverse(c, d, n - n / 2);
        swap(c, d);

        bool flag = true;
        ListNode* it2 = c; it = head;
        for(int i = 0; i < n / 2; ++i){
            if(it->val != it2->val){
                flag = false;
            }
            it = it->next;
            it2 = it2->next;
        }

        reverse(c, d, n - n / 2);
        swap(c, d);
        b->next = c;

        return flag;
    }
};