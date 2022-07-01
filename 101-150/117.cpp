/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        Node *level = root;

        while (level)
        {
            Node *prev = new Node(-1), *it = prev;
            while (level)
            {
                if (level->left)
                {
                    it = it->next = level->left;
                }
                if (level->right)
                {
                    it = it->next = level->right;
                }
                level = level->next;
            }

            level = prev->next;
        }

        return root;
    }
};