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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *prev = new ListNode(-1);
        ListNode *it = prev;

        while (list1 || list2)
        {
            bool flag;
            if (!list1)
            {
                flag = true;
            }
            else if (!list2)
            {
                flag = false;
            }
            else
            {
                flag = (list1->val >= list2->val);
            }

            if (flag)
            {
                ListNode *tmp = new ListNode(list2->val);
                it->next = tmp;
                it = tmp;
                list2 = list2->next;
            }
            else
            {
                ListNode *tmp = new ListNode(list1->val);
                it->next = tmp;
                it = tmp;
                list1 = list1->next;
            }
        }

        return prev->next;
    }
};