/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *prev = new ListNode(-1, head);
        ListNode *slow = prev, *fast = prev;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                auto tmp = prev;
                while (tmp != slow)
                {
                    tmp = tmp->next;
                    slow = slow->next;
                }
                return slow;
            }
        }

        return nullptr;
    }
};