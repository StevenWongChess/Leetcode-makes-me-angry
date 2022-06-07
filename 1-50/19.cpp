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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *prev = new ListNode(-1, head);
        ListNode *slow = prev;
        ListNode *fast = prev;

        for (int i = 0; i < n; ++i)
        {
            fast = fast->next;
        }

        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        auto tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;

        return prev->next;
    }
};