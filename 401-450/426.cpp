/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* head = nullptr, *tail = nullptr;
    
    Node* treeToDoublyList(Node* root) {
        if(!root)
            return nullptr;
        dfs(root);
        head->left = tail;
        tail->right = head;
        return head;
    }
    
    void dfs(Node* root){
        if(!root){
            return;
        }
        dfs(root->left);
        if(head){
            tail->right = root;
            root->left = tail;
        }
        else{
            head = root;
        }
        tail = root;
        dfs(root->right);
    }
};