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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)   return head;
        Node* it = head;
        while(it){
            Node* copy = new Node(it->val);
            copy->next = it->next;
            it->next = copy;
            it = it->next->next;
        }
        it = head;
        while(it){
            if(it->random){
                it->next->random = it->random->next;
            }
            it = it->next->next;
        }
        it = head;
        Node* first = head->next;
        while(it){
            Node* tmp = it->next->next;
            it->next->next = tmp ? tmp->next : nullptr;
            it->next = tmp;
            it = tmp;
        }
        return first;
    }
};