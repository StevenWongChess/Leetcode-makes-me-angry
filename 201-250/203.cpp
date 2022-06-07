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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *prev = new ListNode(-1, head);
        ListNode *it = prev;

        while (it->next)
        {
            if (it->next->val == val)
            {
                auto tmp = it->next;
                it->next = it->next->next;
                delete tmp;
            }
            else
            {
                it = it->next;
            }
        }

        return prev->next;
    }
};