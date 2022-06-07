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
    ListNode *plusOne(ListNode *head)
    {
        ListNode *prev = new ListNode(0, head);
        ListNode *it = prev;
        ListNode *last = prev;
        while (it)
        {
            if (it->val != 9)
            {
                last = it;
            }
            it = it->next;
        }

        ++last->val;
        last = last->next;
        while (last)
        {
            last->val = 0;
            last = last->next;
        }

        return prev->val == 1 ? prev : head;
    }
};