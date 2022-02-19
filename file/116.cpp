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

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;
        Node* row = root;
        while(row->left){
            Node* it = row;
            while(it){
                it->left->next = it->right;
                if(it->next)
                    it->right->next = it->next->left;
                it = it->next;
            }
            row = row->left;
        }
        return root;
    }
};