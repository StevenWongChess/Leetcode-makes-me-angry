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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *prev = new ListNode(-1, head);
        ListNode *it = prev;

        while (it->next && it->next->next)
        {
            auto a = it->next;
            auto b = a->next;
            ListNode *c = b->next;
            it->next = b;
            b->next = a;
            a->next = c;
            it = a;
        }

        return prev->next;
    }
};