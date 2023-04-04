/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *dummy = new Node(-1, nullptr, head, nullptr), *it = head;
        while(it){
            if(it->child){
                Node *tmp = it->next, *child = it->child;
                it->next = child;
                child->prev = it;
                it->child = nullptr;
                Node* last = it;
                while(last->next)
                    last = last->next;
                last->next = tmp;
                if(tmp)
                    tmp->prev = last;
            }
            it = it->next;
        }
        return dummy->next;
    }
};