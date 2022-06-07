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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *dummy1 = new ListNode(-1);
        ListNode *dummy2 = new ListNode(-1);
        ListNode *l = dummy1, *r = dummy2;

        while (head)
        {
            if (head->val < x)
            {
                l->next = head;
                l = l->next;
            }
            else
            {
                r->next = head;
                r = r->next;
            }
            head = head->next;
        }
        l->next = dummy2->next;
        r->next = nullptr;

        return dummy1->next;
    }
};