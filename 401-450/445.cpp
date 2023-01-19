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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        ListNode* it = l1;
        while(it){
            s1.push(it->val);
            it = it->next;
        }
        it = l2;
        while(it){
            s2.push(it->val);
            it = it->next;
        }
        
        int carry = 0;
        ListNode* ans = nullptr;
        while(!s1.empty() || !s2.empty() || carry != 0){
            int a = 0, b = 0;
            if(!s1.empty()){
                a = s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                b = s2.top();
                s2.pop();
            }
            int sum = a + b + carry;
            carry = sum / 10;
            sum %= 10;
            auto new_node = new ListNode(sum);
            new_node->next = ans;
            ans = new_node;
        }
        
        return ans;
    }
};