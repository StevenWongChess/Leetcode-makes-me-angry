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
        Node* row = root;
        Node* tmp = new Node;
        while(row){
            Node* start = tmp; tmp->next = nullptr;
            while(row){
                if(row->left){
                    start->next = row->left;
                    start = row->left;
                }
                if(row->right){
                    start->next = row->right;
                    start = row->right;
                }
                row = row->next;
            }
            row = tmp->next;
        }
        return root;
    }
};