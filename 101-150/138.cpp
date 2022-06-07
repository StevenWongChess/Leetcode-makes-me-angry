/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return head;

        Node *it = head;
        while (it)
        {
            auto next_it = it->next;
            Node *tmp = new Node(it->val);
            it->next = tmp;
            tmp->next = next_it;
            it = next_it;
        }

        it = head;
        while (it)
        {
            it->next->random = it->random ? it->random->next : nullptr;
            it = it->next->next;
        }

        it = head;

        auto ans = new Node(-1);
        auto ans_it = ans;

        while (it)
        {
            auto tmp = it->next;
            it->next = it->next->next;
            ans_it->next = tmp;
            it = it->next;
            ans_it = ans_it->next;
        }

        ans_it->next = nullptr;
        return ans->next;
        ;
    }
};