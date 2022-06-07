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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *prev = new ListNode(-101, head);
        ListNode *it = prev;

        while (it->next)
        {
            if (it->val != it->next->val)
            {
                it = it->next;
            }
            else
            {
                // auto tmp = it->next;
                it->next = it->next->next;
                // delete tmp;
            }
        }

        return prev->next;
    }
};