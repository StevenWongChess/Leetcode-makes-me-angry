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
class Solution
{
public:
    ListNode *mergeTwo(ListNode *a, ListNode *b)
    {
        ListNode *prev = new ListNode(-1);
        ListNode *it = prev;

        while (a && b)
        {
            if (a->val < b->val)
            {
                it->next = a;
                a = a->next;
            }
            else
            {
                it->next = b;
                b = b->next;
            }
            it = it->next;
        }
        it->next = a ? a : b;

        return prev->next;
    }

    ListNode *merge(vector<ListNode *> &lists, int l, int r)
    {
        if (l == r)
            return lists[l];
        else if (l < r)
        {
            int mid = (l + r) / 2;
            return mergeTwo(merge(lists, l, mid), merge(lists, mid + 1, r));
        }
        else
            return nullptr;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int n = lists.size();
        return merge(lists, 0, n - 1);

        //         int n = lists.size();
        //         auto cmp = [](ListNode* a, ListNode* b){return a->val > b->val;};
        //         priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        //         for(auto i: lists){
        //             if(i)
        //                 pq.push(i);
        //         }

        //         ListNode *prev = new ListNode(-1);
        //         ListNode *it = prev;

        //         while(!pq.empty()){
        //             auto i = pq.top();
        //             pq.pop();
        //             it->next = i;
        //             it = it->next;
        //             if(i->next){
        //                 pq.push(i->next);
        //             }
        //         }

        //         return prev->next;
    }
};