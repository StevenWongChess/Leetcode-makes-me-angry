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
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto fun = [](ListNode* a, ListNode* b){return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(fun)> q(fun);
        for(auto i:lists){
            if(i)
                q.push(i);
        }
        ListNode* prev = new ListNode(-1, nullptr);
        ListNode* it = prev;
        while(!q.empty()){
            auto mini = q.top();
            q.pop();
            it->next = mini;
            it = mini;
            if(it->next)
                q.push(it->next);
        }
        return prev->next;
    }
};